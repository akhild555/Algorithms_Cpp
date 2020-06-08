#include <sstream>
#include <vector>

using std::vector;
using std::string;

string largest_number(vector<string> a) {
    
    std::stringstream ret;

    // Compare each element with the rest to see which concatenation produces larger result
    for (size_t i = 0; i < a.size() - 1; ++i)
    {
        for (size_t j = i + 1; j < a.size(); ++j) 
        {
            if (i == j) {
                    
            }
            else
            {
                int first = std::stoi(a[i] + a[j]);
                int second = std::stoi(a[j] + a[i]);            
                if (second > first)
                {
                    std::swap(a[i], a[j]); // swap positions of elements if second concatenation is larger
                }
                
            }
        }
    }

    // pass sorted elements of a to stringstream
    for (size_t i = 0; i < a.size(); ++i)
    {
        ret << a[i];
    }

    string result;
    ret >> result;
    return result;
}