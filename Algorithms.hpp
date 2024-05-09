//ID - 208768978
//GMAIL - michibinyamin@gmail.com

// If this HPP file was defined, then it prevents it from being defind twice.
// If it was not defined then it definds it. 
// Can also use pragme1
#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"
#include <string>

using ariel::Graph;

namespace ariel {
    class Algorithms{
        Algorithms(){}  // Private constructor prevents us from creating an object of algorithms
        // i add static so that they can be reached without creating a class object, this must be done for the given tests and demo to work
        public :
            static bool isConnected(const Graph& g);                       // האלגוריתם מקבל גרף ומחזיר 1 אם הגרף קשיר (אחרת מחזיר 0).
            static std::string shortestPath(const Graph& g,int start,int end);    // האלגוריתם מקבל גרף, קודקוד התחלה וקודקוד סיום ומחזיר את המסלול הקל ביותר (במקרה שהגרף לא ממושקל - הקצר ביותר) בין שני הקודקודים. במידה ואין מסלול כזה, האלגוריתם יחזיר -1.
            static std::string isContainsCycle(const Graph& g);                   // האלגוריתם מקבל גרף ומדפיס מעגל כלשהו. אם לא קיים מעגל בגרף, האלגוריתם יחזיר 0.
            static std::string isBipartite(const Graph& g);                       // האלגוריתם מקבל גרף ומחזיר את החלוקה של הגרף לגרף דו-צדדי. אם אי אפשר לחלק את הגרף, האלגוריתם יחזיר 0.
            static std::string negativeCycle(const Graph& g);                    // האלגוריתם מקבל גרף ומוצא מעגל שלילי (כלומר מעגל שסכום המשקלים של הצלעות שלילי). אם לא קיים מעגל כזה, האלגוריתם ידפיס שלא קיים מעגל שלילי.
    };
}
#endif