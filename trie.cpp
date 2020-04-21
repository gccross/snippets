#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class trie
{
	struct node
	{
		wchar_t val;
		unordered_map<wchar_t,unique_ptr<node>> children;
		explicit node(wchar_t _val) : val(_val){};
	};

	node root;

public:
	
	trie() : root(L'า'){};

	vector<wstring>  match(wstring s)
	{
		wstring prefix;
		node * n = &root;
		for (wstring::iterator s_it = s.begin(); s_it < s.end() ; ++s_it)
		{
				
			unordered_map<wchar_t,unique_ptr<node>>::iterator h_it = n->children.find(*s_it);
			if (h_it != n->children.end())
			{
				prefix.push_back(*s_it);	
				n = h_it->second.get();
			}
			else
					break;
		}
			
		vector<wstring> matches;
		for (unordered_map<wchar_t,unique_ptr<node>>::iterator it = n->children.begin(); it != n->children.end(); ++it)
		{
			vector<wstring> suffixes = get_suffixes(it->second.get());	
			transform(suffixes.begin(), 
				suffixes.end(),
				back_inserter(matches), 
				[&prefix](const wstring& suffix)
				{
					return prefix + suffix;		
				});
		}
		return matches;
	}

	pair<node*,bool>  insert(wstring s)
	{
		node * n = &root;

		wstring::const_iterator s_it ;
		for (s_it= s.begin(); s_it < s.end(); ++s_it)
		{

			unordered_map<wchar_t, unique_ptr<node>>::iterator it = n->children.find(*s_it);
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
			pair<unordered_map<wchar_t, unique_ptr<node>>::iterator, bool> res = n->children.insert(make_pair(*s_it, n_new.release()));
			n = res.first->second.get();
		}
		return make_pair(n, true);
	}

private:


	vector<wstring> get_suffixes(node* const n)
	{
		vector<wstring> suffixes;
		if (n->children.empty()) 
		{
			// what are we going to do here? 
			return suffixes.emplace_back(
		}

		wstring s;
		for (unordered_map<wchar_t,unique_ptr<node>> it = node->children.begin(); 
			it < node->children.end();
			++it)
		{
			vector<wstring> temp = get_suffixes(it->second.get());
			copy(temp.begin(), temp.end(), back_inserter(suffixes));
		}
		return suffixes;
	}
};

int main()
{

	
	string s("This is a dog.");
	stringstream sm(s);
	vector<string> words;
	copy(istream_iterator<string>(sm), istream_iterator<string>(), back_inserter(words));
	
	cout << words.back() << endl;

	return 0;
}

