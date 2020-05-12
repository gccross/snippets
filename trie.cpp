#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

template<class T>
class trie
{
	struct node_t
	{
		T val;
		vector<trie<T>> children;
		explicit node_t(const T&  _val) : val(_val){};
	};

	unique_ptr<node_t> root;

public:
	
	using iterator_type = typename vector<trie<T>>::iterator;
	using const_iterator_type = typename vector<trie<T>>::const_iterator;

	trie() =  default;
	explicit trie(const T& val): root(make_unique<node_t>(val)) {};

	T& val() const { return root->val; } 

	vector<basic_string<T>>  match(const basic_string<T> & s)
	{
		basic_string<T> prefix;
		node_t const* n = root.get();
		for (typename basic_string<T>::const_iterator s_it = s.cbegin(); s_it < s.cend() ; ++s_it)
		{
			const_iterator_type h_it = lower_bound(n->children.cbegin(), n->children.cend(), *s_it);
			if (h_it != n->children.cend() && !(*s_it < *h_it)) // value exists
			{
				prefix.push_back(*s_it);	
				n = h_it->root.get();
			}
			else
				break;
		}
			
		vector<basic_string<T>> matches;
		for (const_iterator_type it = n->children.cbegin(); it != n->children.cend(); ++it)
		{
			vector<basic_string<T>> suffixes = get_suffixes(it);	
			transform(suffixes.cbegin(), 
				suffixes.cend(),
				back_inserter(matches), 
				[&prefix](const basic_string<T>& suffix)
				{
					return prefix + suffix;		
				});
		}
		return matches;
	}

	pair<const_iterator_type,bool>  insert(basic_string<T> const & s)
	{
		if (s.empty()) return(make_pair(vector<trie<T>>().cend(),false));
		if (!root) root = make_unique<node_t>(s[0]);
		node_t * n = root.get();

		typename basic_string<T>::const_iterator s_it ;
		typename vector<trie<T>>::const_iterator it;
		for (s_it = s.begin(); s_it < s.end(); ++s_it)
		{

			it = lower_bound(n->children.cbegin(), n->children.cend(), *s_it);
			if (it != n->children.cend() && !(*s_it < *it))
				n = it->root.get();
			else break;
		}

		if (s_it == s.end()) return make_pair(it,false);

		for (;s_it < s.end(); ++s_it)
		{
			n->children.emplace_back(*s_it);
			sort(n->children.begin(), n->children.end()); 
			it = lower_bound(n->children.cbegin(), n->children.cend(), *s_it);
			n = it->root.get();
		}
		return make_pair(it, true);
	}

private:


	vector<basic_string<T>> get_suffixes(const_iterator_type it)
	{
		node_t const* n = it->root.get();
		vector<basic_string<T>> suffixes;
		if (n->children.empty()) 
		{
			suffixes.emplace_back(1,n->val);
			return suffixes;
		}

		basic_string<T> s;
		vector<basic_string<T>> temp;

		for (const_iterator_type it = n->children.cbegin(); 
			it != n->children.cend();
			++it)
		{
			temp = get_suffixes(it);
		}
		for (basic_string<T>& s: temp) s = n->val + s;
		copy(temp.cbegin(), temp.cend(), back_inserter(suffixes));
		return suffixes;
	}
};

template <typename T>
bool operator< (const trie<T>& l, const trie<T>& r) { return l.val() < r.val(); };
template <typename T>
bool operator< (const T& l, const trie<T>& r) { return l < r.val(); };
template <typename T>
bool operator< (const trie<T>& l, const T& r) { return l.val() < r; };

int main()
{

	
	string s("bard barstool barraster barn barndoor brindille breezy broach");
	stringstream sm(s);
	vector<string> words;
	copy(istream_iterator<string>(sm), istream_iterator<string>(), back_inserter(words));
	
	cout << words.back() << endl;
	trie<char> t;
	for (string const& w: words) t.insert(w);
	for (string const& w: t.match("bar")) cout << w << endl;
	for (string const& w: t.match("br")) cout << w << endl;

	return 0;
}

