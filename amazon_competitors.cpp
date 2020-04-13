#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> topNCompetitors(int numCompetitors, 
				int topNCompetitors, 
				vector<string> competitors, 
				int numReviews,
				vector<string> reviews)
{
	auto tolowerstring = [](string & word) 
	{ 
		for (int i=0; i<word.length(); ++i)
		{
			char c = tolower(word[i]);
			word[i] = c;
		}
	};

	unordered_set<size_t> length_hash;
	unordered_map<string,size_t> scores_hash;
	
	for (string competitor : competitors)
	{
		length_hash.insert(competitor.length());
		tolowerstring(competitor);
		scores_hash.insert(make_pair(competitor, 0));
	}

	for (int i = 0; i<numReviews; ++i) 
	{
		string review;
		stringstream stm(reviews[i]);
		while (stm)
		{
			string word;
			stm >> word;

			if (length_hash.find(word.length()) == length_hash.end()) continue;

			tolowerstring(word);
			unordered_map<string, size_t>::iterator it = scores_hash.find(word);
			if (it != scores_hash.end())
			{
				it->second++;
				break;
			}
				
		}
	}

	vector<pair<string,size_t>> scores_sorted(scores_hash.begin(), scores_hash.end());
	nth_element(scores_sorted.begin(), scores_sorted.begin() + topNCompetitors, scores_sorted.end(),
		[](const pair<string,size_t>& left, const pair<string,size_t>& right ) -> bool
		{
			return left.second > right.second;	
			
		});

	vector<string> res;
	for (int i=0; i<topNCompetitors; ++i) res.emplace_back(scores_sorted[i].first);
	
	return res;

}


int main (int argc, char const * argv[])
{
	
	cout << "Hello World " __FILE__ << endl;
	vector<string> competitors;
	vector<string> reviews;

	competitors.emplace_back("sunDAY");
	competitors.emplace_back("monDAY");
	competitors.emplace_back("tuESDay");
	competitors.emplace_back("wednESDAy");
	competitors.emplace_back("thURSDay");
	competitors.emplace_back("fridAy");
	competitors.emplace_back("satuRday");

	reviews.emplace_back("On sunday we go to church");
	reviews.emplace_back("Monday wash day. The day of the moon is Monday.");
	reviews.emplace_back("One usually wakes up by Tuesday.  Like say TUESDAY!!! ITS TUESDAY!!!");
	reviews.emplace_back("Last week on WEdnesday we played badminton and bingo");
	reviews.emplace_back("Fish is for FridaY.  Every fRIday we must have fish otherwise something is fishy");
	reviews.emplace_back("Saturday night's alright for fighting.  Get a little action in.");
	reviews.emplace_back("One's Tuesday is usually how the week begins. ");
	reviews.emplace_back("Fishday is for fridaY.  Evedry fRIday we must absolutely have fish catch of the day");
	reviews.emplace_back("THe worst drivers emerge on SUNday's");
	vector<string> res = topNCompetitors(competitors.size(),3, competitors, reviews.size(), reviews);

	copy( res.begin(), res.end(), ostream_iterator<string>(cout, "\t"));
				
	return 0;
}
/*
Amazon wants to develop a more efficient way of evaluating their top N
competitors for the latest Echo device.  For this analysis, they have developed
an automated web crawler that identifies websites where users have written
reviews about Amazon’s competitors.  To get a sense of the different competitors
out there, they want to review these websites to see how often a competitor is
mentioned: ie, a competitor is considered to be strong if its name occurs in
more unique reviews.

Find top N competitors Input: vector<string> rankCompetitors (int
numCompetitors, int numTopCompetitors, vector<string> competitors, int
numReviews, vector<string> reviews

Note: 
* comparisons is case-insensitive multiple occurrences of a competitor in a
* review counts as 1.
eg: Input:

return top=2 competitors = [newshop, shopnow, afshion, fashionbeats, mymarket,
tcellular] reviews = [ “tcellular rules”, “mymarket is the boss”, “asfhion is a
worse effrontery to mankind than facebook” “mymarket for president” ]

Output:

mymarket, asfhion

*/
