/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
#define DEBUG(x) cerr << #x << " is " << (x) << endl;

void sortTheBoardingPasses(unordered_map<string, string> boardingPasses) {
    /*
     * reverse map will contains the mapping in reverse.
     * So for (travel_from_city ---> travel_to_city) in boardingPasses,
     * We will have a reverse mapping, (travel_to_city ---> travel_from_city) entry in reverse map.
     */
    unordered_map<string, string> reverse;
    unordered_map<string, string>::iterator it;
    for(it = boardingPasses.begin(); it != boardingPasses.end(); it++) {
        /*
         * reversing the initial mapping.
         */
        reverse[it->second] = it->first;
    }
    string sourceCityName = "";
    for(it = boardingPasses.begin(); it != boardingPasses.end(); it++) {
        if(reverse.find(it->first) == reverse.end()) {
            /*
             * The city which does not have a 'travel_from_city' entry in reverse map,
             * Actually is the starting point because you are not going to that city from any other one.
             */
            sourceCityName = it->first;
            break;
        }
    }
    /*
     * Now that, We have found our start city, use the initial mapping to traverse the route till the END.
     */
    it = boardingPasses.find(sourceCityName);
    cout << "\nfollowing is the sorted order of the boarding passes for your trip.\n\n";
    while(it!=boardingPasses.end()) {
        cout << (it->first) << " " << (it->second) << endl;
        it = boardingPasses.find(it->second);
    }
}

int main() {
    string sourceCityName = "", destinationCityName = "";
    int numberOfPasses = 0;
    /*
     * boardingPasses map contains the information about the
     * passes in the form of a mapping : travel_from_city ---> travel_to_city
     */
    unordered_map<string, string> boardingPasses;
    cout << "Please provide the input in following format.\n\nN (number of passes)\nSource-City destination-City\n.\n.\n.\nN times\n\n";
    cin >> numberOfPasses;
    for (int i=1; i <= numberOfPasses; i++) {
        cin >> sourceCityName;
        cin >> destinationCityName;
        boardingPasses[sourceCityName] = destinationCityName;
    }
    sortTheBoardingPasses(boardingPasses);
    return 0;
}


