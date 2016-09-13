//
// Created by adil on 11/9/16.
//

#include <string>;
#include <vector>;
#include <algorithm>;

/**
 * You can either use every class type on one line ..
 */
//using std::string;
//using std::vector;
//using std::find_if;
//using std::find;

/**
 * .. OR, just import the std namespace
 */
using namespace std;

string::const_iterator url_beg(string::const_iterator b, string::const_iterator e)
{
    static const string sep = "://";
    typedef string::const_iterator iter;

    //i marks where the separator was found
    iter i = b;

    while( (i = search(i, e, sep.begin(), sep.end())) != e)
    {
        if(i != b && i + sep.size() != e) {

            //beg marks the beginning of the protocol name
            iter beg = i;
            while(beg != b && isalpha(beg[-1]))
                --beg;

            // is there at least one appropriate char befire and after the separator?
            if (beg != i && !not_url_char(i[sep.size()]))
                return beg;
        }

        // the separator we found wasn't part of a URL; advance i past this
        i += sep.size();
    }

    return e;
}

vector<string> find_urls(const string& s)
{
    vector<string> ret;
    typedef string::const_iterator iter;
    iter b = s.begin(), e = s.end();

    while(b != e) {
        b = url_beg(b, e);

        if(b != e) {
            iter after = url_end(b, e);
            ret.push_back(string(b, after));
            b = after;
        }
    }

    return ret;
}

string::const_iterator
url_end(string::const_iterator b, string::const_iterator e)
{
    return find_if(b, e, not_url_char);
}

bool not_url_char(char c)
{
    static const string url_ch = "~;/?:@=&$-_.+*`(),";

    return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}