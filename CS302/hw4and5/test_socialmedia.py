# Lian Zhu
# test_socialmedia.py
# CS302 Program 4

import pytest
import numpy as np
from socialmedia import SocialMedia, LinkedIn, TikTok, Snapchat


# --------------------
# Base Class Tests
# --------------------
def test_socialmedia_constructor_valid():
    sm = SocialMedia("lian", 100)
    assert sm._username == "lian"
    assert sm._followers == 100
    assert isinstance(sm._follower_history, np.ndarray)
    assert len(sm._follower_history) == 1


def test_socialmedia_constructor_empty_username():
    with pytest.raises(ValueError, match="Username must be a non-empty string"):
        SocialMedia("", 50)


def test_socialmedia_constructor_whitespace_username():
    with pytest.raises(ValueError, match="Username must be a non-empty string"):
        SocialMedia("   ", 50)


def test_socialmedia_constructor_negative_followers():
    with pytest.raises(ValueError, match="followers must be a non-negative integer"):
        SocialMedia("sam", -1)


def test_socialmedia_constructor_invalid_followers_type():
    with pytest.raises(ValueError, match="followers must be a non-negative integer"):
        SocialMedia("sam", "abc")


def test_socialmedia_constructor_float_followers():
    with pytest.raises(ValueError, match="followers must be a non-negative integer"):
        SocialMedia("sam", 10.5)


def test_update_followers_valid():
    sm = SocialMedia("lian", 100)
    result = sm.update_followers(50)
    assert sm._followers == 50
    assert result == 50
    assert len(sm._follower_history) == 2


def test_update_followers_negative():
    sm = SocialMedia("lian", 100)
    with pytest.raises(ValueError, match="follower count must be a non-negative integer"):
        sm.update_followers(-10)


def test_update_followers_non_int():
    sm = SocialMedia("lian", 100)
    with pytest.raises(ValueError, match="follower count must be a non-negative integer"):
        sm.update_followers("bad")


def test_socialmedia_display():
    sm = SocialMedia("lian", 100)
    output = sm.display()
    assert isinstance(output, str)
    assert "lian" in output
    assert "100" in output


def test_socialmedia_lt_operator_true():
    sm1 = SocialMedia("user1", 50)
    sm2 = SocialMedia("user2", 100)
    assert sm1 < sm2


def test_socialmedia_lt_operator_false():
    sm1 = SocialMedia("user1", 200)
    sm2 = SocialMedia("user2", 100)
    assert not (sm1 < sm2)


def test_socialmedia_lt_operator_equal():
    sm1 = SocialMedia("user1", 100)
    sm2 = SocialMedia("user2", 100)
    assert not (sm1 < sm2)


def test_socialmedia_lt_operator_invalid_type():
    sm = SocialMedia("user1", 100)
    with pytest.raises(TypeError, match="Comparison only allowed between SocialMedia types"):
        sm < "invalid"


def test_socialmedia_add_operator():
    sm1 = SocialMedia("user1", 100)
    sm2 = SocialMedia("user2", 50)
    result = sm1 + sm2
    assert result._followers == 150
    assert "user1" in result._username
    assert "user2" in result._username


def test_socialmedia_add_operator_invalid_type():
    sm = SocialMedia("user1", 100)
    with pytest.raises(TypeError, match="Addition only allowed between SocialMedia types"):
        sm + 50

# --------------------
# LinkedIn Tests
# --------------------
def test_linkedin_constructor_valid():
    ln = LinkedIn("lian", 100, 50, 10)
    assert ln._username == "lian"
    assert ln._followers == 100
    assert ln._connections == 50
    assert ln._posts == 10
    assert isinstance(ln._recent_posts, list)


def test_linkedin_add_connection():
    ln = LinkedIn("lian", 100, 0, 0)
    result = ln.add_connection()
    assert ln._connections == 1
    assert result == 1


def test_linkedin_add_post_default():
    ln = LinkedIn("lian", 100, 0, 0)
    result = ln.add_post()
    assert ln._posts == 1
    assert result == 1
    assert len(ln._recent_posts) == 1


def test_linkedin_add_post_with_title():
    ln = LinkedIn("lian", 100, 0, 0)
    ln.add_post("My First Post")
    assert "My First Post" in ln._recent_posts


def test_linkedin_calculate_reach():
    ln = LinkedIn("lian", 100, 10, 5)
    reach = ln.calculate_reach()
    assert isinstance(reach, int)
    assert reach == 100 + (10 * 2)


def test_linkedin_invalid_connections():
    with pytest.raises(ValueError, match="connections must be a non-negative integer"):
        LinkedIn("lian", 10, -1, 0)


def test_linkedin_invalid_posts():
    with pytest.raises(ValueError, match="posts must be a non-negative integer"):
        LinkedIn("lian", 10, 0, -5)


def test_linkedin_display():
    ln = LinkedIn("lian", 100, 10, 5)
    output = ln.display()
    assert "lian" in output
    assert "100" in output
    assert "Connections: 10" in output
    assert "Posts: 5" in output
    assert "Reach:" in output


def test_linkedin_add_operator():
    ln1 = LinkedIn("user1", 100, 50, 10)
    ln2 = LinkedIn("user2", 50, 30, 5)
    result = ln1 + ln2
    assert isinstance(result, LinkedIn)
    assert result._followers == 150
    assert result._connections == 80
    assert result._posts == 15


def test_linkedin_add_operator_invalid_type():
    ln = LinkedIn("user1", 100, 50, 10)
    sm = SocialMedia("user2", 50)
    with pytest.raises(TypeError, match="Can only merge with another LinkedIn profile"):
        ln + sm

# --------------------
# TikTok Tests
# --------------------
def test_tiktok_constructor_valid():
    tt = TikTok("lian", 100, 5, 1000)
    assert tt._username == "lian"
    assert tt._followers == 100
    assert tt._videos == 5
    assert tt._total_views == 1000
    assert isinstance(tt._video_list, list)


def test_tiktok_add_video_valid():
    tt = TikTok("lian", 100, 0, 0)
    result = tt.add_video(500)
    assert tt._videos == 1
    assert tt._total_views == 500
    assert result == 1
    assert 500 in tt._video_list


def test_tiktok_add_video_negative():
    tt = TikTok("lian", 100, 0, 0)
    with pytest.raises(ValueError, match="views must be a non-negative integer"):
        tt.add_video(-50)


def test_tiktok_average_views():
    tt = TikTok("lian", 100, 2, 1000)
    assert tt.average_views() == 500


def test_tiktok_average_zero():
    tt = TikTok("lian", 100, 0, 0)
    assert tt.average_views() == 0


def test_tiktok_is_trending_true():
    tt = TikTok("lian", 100, 2, 3000)
    assert tt.is_trending() is True


def test_tiktok_is_trending_false():
    tt = TikTok("lian", 100, 2, 200)
    assert tt.is_trending() is False


def test_tiktok_is_trending_exactly_1000():
    tt = TikTok("lian", 100, 1, 1000)
    assert tt.is_trending() is False


def test_tiktok_invalid_videos():
    with pytest.raises(ValueError, match="videos must be a non-negative integer"):
        TikTok("lian", 10, -1, 0)


def test_tiktok_invalid_total_views():
    with pytest.raises(ValueError, match="total_views must be a non-negative integer"):
        TikTok("lian", 10, 0, -100)


def test_tiktok_display():
    tt = TikTok("lian", 100, 2, 3000)
    output = tt.display()
    assert "lian" in output
    assert "100" in output
    assert "Videos: 2" in output
    assert "Total Views: 3000" in output
    assert "Avg Views:" in output
    assert "Trending" in output


def test_tiktok_add_operator():
    tt1 = TikTok("user1", 100, 5, 1000)
    tt2 = TikTok("user2", 50, 3, 500)
    result = tt1 + tt2
    assert isinstance(result, TikTok)
    assert result._followers == 150
    assert result._videos == 8
    assert result._total_views == 1500


def test_tiktok_add_operator_invalid_type():
    tt = TikTok("user1", 100, 5, 1000)
    sm = SocialMedia("user2", 50)
    with pytest.raises(TypeError, match="Can only merge with another TikTok profile"):
        tt + sm

# --------------------
# Snapchat Tests
# --------------------
def test_snapchat_constructor_valid():
    sc = Snapchat("lian", 100, 50, 10)
    assert sc._username == "lian"
    assert sc._followers == 100
    assert sc._snaps_sent == 50
    assert sc._streak_days == 10
    assert isinstance(sc._snap_history, list)


def test_snapchat_send_snap_default():
    sc = Snapchat("lian", 100, 0, 0)
    result = sc.send_snap()
    assert sc._snaps_sent == 1
    assert result == 1
    assert len(sc._snap_history) == 1


def test_snapchat_send_snap_multiple():
    sc = Snapchat("lian", 100, 0, 0)
    result = sc.send_snap(5)
    assert sc._snaps_sent == 5
    assert result == 5


def test_snapchat_send_snap_negative():
    sc = Snapchat("lian", 100, 0, 0)
    with pytest.raises(ValueError, match="snap count must be a non-negative integer"):
        sc.send_snap(-1)


def test_snapchat_increase_streak():
    sc = Snapchat("lian", 100, 0, 0)
    result = sc.increase_streak()
    assert sc._streak_days == 1
    assert result == 1


def test_snapchat_increase_streak_multiple():
    sc = Snapchat("lian", 100, 0, 5)
    sc.increase_streak()
    sc.increase_streak()
    assert sc._streak_days == 7


def test_snapchat_reset_streak():
    sc = Snapchat("lian", 100, 0, 5)
    result = sc.reset_streak()
    assert sc._streak_days == 0
    assert result == 0


def test_snapchat_invalid_snaps():
    with pytest.raises(ValueError, match="snaps_sent must be a non-negative integer"):
        Snapchat("lian", 10, -1, 0)


def test_snapchat_invalid_streak():
    with pytest.raises(ValueError, match="streak_days must be a non-negative integer"):
        Snapchat("lian", 10, 0, -5)


def test_snapchat_display():
    sc = Snapchat("lian", 100, 50, 10)
    output = sc.display()
    assert "lian" in output
    assert "100" in output
    assert "Snaps Sent: 50" in output
    assert "Streak: 10 days" in output


def test_snapchat_add_operator():
    sc1 = Snapchat("user1", 100, 50, 10)
    sc2 = Snapchat("user2", 50, 30, 15)
    result = sc1 + sc2
    assert isinstance(result, Snapchat)
    assert result._followers == 150
    assert result._snaps_sent == 80
    assert result._streak_days == 15


def test_snapchat_add_operator_invalid_type():
    sc = Snapchat("user1", 100, 50, 10)
    sm = SocialMedia("user2", 50)
    with pytest.raises(TypeError, match="Can only merge with another Snapchat profile"):
        sc + sm


def test_mixed_platform_comparison():
    ln = LinkedIn("lian", 100, 50, 10)
    tt = TikTok("sam", 200, 5, 1000)
    sc = Snapchat("alex", 150, 50, 10)
    assert ln < tt
    assert ln < sc
    assert sc < tt


def test_follower_history_tracking():
    sm = SocialMedia("lian", 100)
    sm.update_followers(150)
    sm.update_followers(200)
    assert len(sm._follower_history) == 3
    assert sm._follower_history[0] == 100
    assert sm._follower_history[1] == 150
    assert sm._follower_history[2] == 200