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
