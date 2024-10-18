#include <gtest/gtest.h>
#include "design_browser_history.h"

TEST(DesignBrowserHistory, Constructor_Works)
{
    string startStr = "leetcode.com";
    BrowserHistory browserHistory(startStr);
    ASSERT_EQ(browserHistory.ToStr(), startStr);
    ASSERT_EQ(browserHistory.ToStrReverse(), startStr);
}

TEST(DesignBrowserHistory, VisitOnly_Works)
{
    string startStr = "leetcode.com";
    BrowserHistory browserHistory(startStr);
    browserHistory.visit("google.com");
    browserHistory.visit("facebook.com");
    browserHistory.visit("youtube.com");
    ASSERT_EQ(browserHistory.ToStr(), "leetcode.com google.com facebook.com youtube.com");
    ASSERT_EQ(browserHistory.ToStrReverse(), "youtube.com facebook.com google.com leetcode.com");
}

TEST(DesignBrowserHistory, VisitClearsForwardHistory_Works)
{
    string startStr = "leetcode.com";
    BrowserHistory browserHistory(startStr);
    browserHistory.visit("google.com");
    browserHistory.visit("facebook.com");
    browserHistory.visit("youtube.com");

    browserHistory.back(2);
    browserHistory.visit("a.com");


    ASSERT_EQ(browserHistory.ToStr(), "leetcode.com google.com a.com");
    ASSERT_EQ(browserHistory.ToStrReverse(), "a.com google.com leetcode.com");
}


TEST(DesignBrowserHistory, back_InBoundaries_Works)
{
    string startStr = "leetcode.com";
    BrowserHistory browserHistory(startStr);

    browserHistory.visit("google.com");
    browserHistory.visit("facebook.com");
    browserHistory.visit("youtube.com");
    browserHistory.visit("a.com");
    browserHistory.visit("b.com");
    browserHistory.visit("c.com");
    browserHistory.visit("d.com");


    auto res = browserHistory.back(1);
    ASSERT_EQ(res, "c.com");

    res = browserHistory.back(2);
    ASSERT_EQ(res, "a.com");

    res = browserHistory.back(4);
    ASSERT_EQ(res, "leetcode.com");
}

TEST(DesignBrowserHistory, back_OutBoundaries_Works)
{
    string startStr = "leetcode.com";
    BrowserHistory browserHistory(startStr);

    browserHistory.visit("google.com");
    browserHistory.visit("facebook.com");

    auto res = browserHistory.back(3);
    ASSERT_EQ(res, "leetcode.com");
}

TEST(DesignBrowserHistory, forward_InBoundaries_Works)
{
    string startStr = "leetcode.com";
    BrowserHistory browserHistory(startStr);

    browserHistory.visit("google.com");
    browserHistory.visit("facebook.com");
    browserHistory.visit("youtube.com");
    browserHistory.visit("a.com");
    browserHistory.visit("b.com");
    browserHistory.visit("c.com");
    browserHistory.visit("d.com");


    auto res = browserHistory.back(5);
    ASSERT_EQ(res, "facebook.com");

    res = browserHistory.forward(3);
    ASSERT_EQ(res, "b.com");

    res = browserHistory.forward(2);
    ASSERT_EQ(res, "d.com");

}

TEST(DesignBrowserHistory, forward_OutBoundaries_Works)
{
    string startStr = "leetcode.com";
    BrowserHistory browserHistory(startStr);

    browserHistory.visit("google.com");
    browserHistory.visit("facebook.com");
    browserHistory.visit("youtube.com");



    auto res = browserHistory.back(2);
    ASSERT_EQ(res, "google.com");

    res = browserHistory.forward(3);
    ASSERT_EQ(res, "youtube.com");
}

TEST(DesignBrowserHistory, leetcodetest_works) 
{
    BrowserHistory browserHistory("leetcode.com");
    browserHistory.visit("google.com");       // You are in "leetcode.com". Visit "google.com"
    browserHistory.visit("facebook.com");     // You are in "google.com". Visit "facebook.com"
    browserHistory.visit("youtube.com");      // You are in "facebook.com". Visit "youtube.com"
    ASSERT_EQ(browserHistory.ToStr(), "leetcode.com google.com facebook.com youtube.com");
    ASSERT_EQ(browserHistory.ToStrReverse(), "youtube.com facebook.com google.com leetcode.com");
    browserHistory.back(1);                   // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
    auto res = browserHistory.back(1);                   // You are in "facebook.com", move back to "google.com" return "google.com"
    res = browserHistory.forward(1);                // You are in "google.com", move forward to "facebook.com" return "facebook.com"
    ASSERT_EQ(res, "facebook.com");
    browserHistory.visit("linkedin.com");     // You are in "facebook.com". Visit "linkedin.com"
    ASSERT_EQ(browserHistory.ToStr(), "leetcode.com google.com facebook.com linkedin.com");
    ASSERT_EQ(browserHistory.ToStrReverse(), "linkedin.com facebook.com google.com leetcode.com");
    res = browserHistory.forward(2);                // You are in "linkedin.com", you cannot move forward any steps.
    ASSERT_EQ(res, "linkedin.com");
    res = browserHistory.back(2);                   // You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
    ASSERT_EQ(res, "google.com");
    res = browserHistory.back(7);                   // You are in "google.com", you can move back only one step to "leetcode.com". return "leetcode.com"
    ASSERT_EQ(res, "leetcode.com");
}