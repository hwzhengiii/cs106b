/* File: OnlyConnect.cpp
 *
 * TODO: Edit these comments to describe anything interesting or noteworthy in your implementation.
 * 循环：遍历字符串，若字符是字母，且不在aeiouAEIOU中，则为需要保留的字符
 * 递归：若字符串长度为0直接返回，不为零则判断第一个字符是否符合要求，若符合则返回其与剩下字符串中符合要求的字符串；若不符合则返回剩下字符串中符合要求的字符串。
 *
 * TODO: Edit these comments to leave a puzzle for your section leader to solve!
 */
#include "OnlyConnect.h"
#include "GUI/SimpleTest.h"
#include <cctype>
#include <string>
using namespace std;

string onlyConnectize(string phrase) {
    /* TODO: The next few lines just exist to make sure you don't get compiler warning messages
     * when this function isn't implemented. Delete these lines, then implement this function.
     */

   // 非递归
//    string model="aeiouAEIOU";
//    string answer="";
//    for(char ch:phrase){
//        if(isalpha(ch) && model.find(ch)==string::npos){
//            answer+=toupper(ch);
//        }
//    }
//    return answer;
    // 递归
    if(phrase.size()==0){
        return "";
    }
    string model="aeiouAEIOU";
    if(isalpha(phrase[0])&&model.find(phrase[0])==string::npos){
        return string("")+char(toupper(phrase[0]))+onlyConnectize(phrase.substr(1));
    }else{
        return onlyConnectize(phrase.substr(1));
    }
}






/* * * * * * Provided Test Cases * * * * * */

PROVIDED_TEST("Converts lower-case to upper-case.") {
    EXPECT_EQUAL(onlyConnectize("lowercase"), "LWRCS");
    EXPECT_EQUAL(onlyConnectize("uppercase"), "PPRCS");
}

PROVIDED_TEST("Handles non-letter characters properly.") {
    EXPECT_EQUAL(onlyConnectize("2.718281828459045"), "");
    EXPECT_EQUAL(onlyConnectize("'Hi, Mom!'"), "HMM");
}

PROVIDED_TEST("Handles single-character inputs.") {
    EXPECT_EQUAL(onlyConnectize("A"), "");
    EXPECT_EQUAL(onlyConnectize("+"), "");
    EXPECT_EQUAL(onlyConnectize("Q"), "Q");
}

/* TODO: You will need to add your own tests into this suite of test cases. Think about the sorts
 * of inputs we tested here, and, importantly, what sorts of inputs we *didn't* test here. Some
 * general rules of testing:
 *
 *    1. Try extreme cases. What are some very large cases to check? What are some very small cases?
 *
 *    2. Be diverse. There are a lot of possible inputs out there. Make sure you have tests that account
 *       for cases that aren't just variations of one another.
 *
 *    3. Be sneaky. Don't just try standard inputs. Try weird ones that you wouldn't expect anyone to
 *       actually enter, but which are still perfectly legal.
 *
 * Happy testing!
 */
PROVIDED_TEST("处理有空格的") {
    EXPECT_EQUAL(onlyConnectize("A   "), "");
    EXPECT_EQUAL(onlyConnectize(" + "), "");
    EXPECT_EQUAL(onlyConnectize("   Q"), "Q");
}





