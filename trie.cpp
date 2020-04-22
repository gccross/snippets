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
	struct node
	{
		T val;
		unordered_map<T,unique_ptr<node>> children;
		explicit node(T _val) : val(_val){};
	};

	node root;

public:
	
	trie() : root(' '){};

	using map_iterator_type = typename unordered_map<T,unique_ptr<node>>::iterator;
	vector<basic_string<T>>  match(const basic_string<T> & s)
	{
		basic_string<T> prefix;
		node * n = &root;
		for (typename basic_string<T>::const_iterator s_it = s.begin(); s_it < s.end() ; ++s_it)
		{
			map_iterator_type h_it = n->children.find(*s_it);
			if (h_it != n->children.end())
			{
				prefix.push_back(*s_it);	
				n = h_it->second.get();
			}
			else
					break;
		}
			
		vector<basic_string<T>> matches;
		for (map_iterator_type it = n->children.begin(); it != n->children.end(); ++it)
		{
			vector<basic_string<T>> suffixes = get_suffixes(it->second.get());	
			transform(suffixes.begin(), 
				suffixes.end(),
				back_inserter(matches), 
				[&prefix](const basic_string<T>& suffix)
				{
					return prefix + suffix;		
				});
		}
		return matches;
	}

	pair<node*,bool>  insert(basic_string<T> const & s)
	{
		node * n = &root;

		typename basic_string<T>::const_iterator s_it ;
		for (s_it = s.begin(); s_it < s.end(); ++s_it)
		{

			map_iterator_type it = n->children.find(*s_it);
			if (it != n->children.end())
			{
				n = it->second.get();
			}
			else break;
		}

		if (s_it == s.end()) return make_pair(n,false);

		for (;s_it < s.end(); ++s_it)
		{
			unique_ptr<node> n_new(make_unique<node>(*s_it));
			pair<map_iterator_type, bool> res = n->children.insert(make_pair(*s_it, n_new.release()));
			n = res.first->second.get();
		}
		return make_pair(n, true);
	}

private:


	vector<basic_string<T>> get_suffixes(node* const n)
	{
		vector<basic_string<T>> suffixes;
		if (n->children.empty()) 
		{
			suffixes.emplace_back(1,n->val);
			return suffixes;
		}

		basic_string<T> s;
		vector<basic_string<T>> temp;

		for (map_iterator_type it = n->children.begin(); 
			it != n->children.end();
			++it)
		{
			temp = get_suffixes(it->second.get());
		}
		for (basic_string<T>& s: temp) s = n->val + s;
		copy(temp.begin(), temp.end(), back_inserter(suffixes));
		return suffixes;
	}
};

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

