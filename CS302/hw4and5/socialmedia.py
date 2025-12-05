# Lian Zhu
# CS 302
# socialmedia.py - Program #4

import numpy as np

# Base class
class SocialMedia:
    
    def __init__(self, username: str, followers: int):
        self._validate_username(username)
        self._validate_nonnegative(followers, "followers")
        self._username = username
        self._followers = followers
        self._follower_history = np.array([followers])

    # Helper functions to validate input
    def _validate_username(self, username):
        if not isinstance(username, str) or username.strip() == "":
            raise ValueError("Username must be a non-empty string.")

    def _validate_nonnegative(self, value, field_name="value"):
        if not isinstance(value, int) or value < 0:
            raise ValueError(f"{field_name} must be a non-negative integer.")

    def update_followers(self, amount: int):
        self._validate_nonnegative(amount, "follower count")
        self._followers = amount
        self._follower_history = np.append(self._follower_history, amount)
        return self._followers

    def display(self):
        return f"User: {self._username}, Followers: {self._followers}"

    # < operator overload
    def __lt__(self, other):
        if not isinstance(other, SocialMedia):
            raise TypeError("Comparison only allowed between SocialMedia types.")
        return self._followers < other._followers
    
    # + operator overload
    def __add__(self, other):
        if not isinstance(other, SocialMedia):
            raise TypeError("Addition only allowed between SocialMedia types.")
        combined_followers = self._followers + other._followers
        combined_username = f"{self._username}+{other._username}"
        return SocialMedia(combined_username, combined_followers)

# Derived LinkedIn class
class LinkedIn(SocialMedia):
    
    def __init__(self, username: str, followers: int, connections: int, posts: int):
        super().__init__(username, followers)
        self._validate_nonnegative(connections, "connections")
        self._validate_nonnegative(posts, "posts")
        self._connections = connections
        self._posts = posts
        self._recent_posts = []

    def add_connection(self):
        self._connections += 1
        return self._connections

    def add_post(self, title: str = "Untitled Post"):
        self._posts += 1
        self._recent_posts.append(title)
        return self._posts

    def calculate_reach(self):
        return self._followers + (self._connections * 2)

    def display(self):
        base = super().display()
        return (f"{base}, Connections: {self._connections}, "
                f"Posts: {self._posts}, Reach: {self.calculate_reach()}")

    def __add__(self, other):
        if not isinstance(other, LinkedIn):
            raise TypeError("Can only merge with another LinkedIn profile.")
        combined_username = f"{self._username}+{other._username}"
        combined_followers = self._followers + other._followers
        combined_connections = self._connections + other._connections
        combined_posts = self._posts + other._posts
        return LinkedIn(combined_username, combined_followers, 
                       combined_connections, combined_posts)

# Derived TikTok class
class TikTok(SocialMedia):
    
    def __init__(self, username: str, followers: int, videos: int, total_views: int):
        super().__init__(username, followers)
        self._validate_nonnegative(videos, "videos")
        self._validate_nonnegative(total_views, "total_views")
        self._videos = videos
        self._total_views = total_views
        self._video_list = []

    def add_video(self, views: int):
        self._validate_nonnegative(views, "views")
        self._videos += 1
        self._total_views += views
        self._video_list.append(views)
        return self._videos

    def average_views(self):
        if self._videos == 0:
            return 0
        return self._total_views // self._videos

    def is_trending(self):
        return self.average_views() > 1000

    def display(self):
        base = super().display()
        trending_status = "Trending" if self.is_trending() else "Not Trending"
        return (f"{base}, Videos: {self._videos}, "
                f"Total Views: {self._total_views}, "
                f"Avg Views: {self.average_views()}, Status: {trending_status}")

    def __add__(self, other):
        if not isinstance(other, TikTok):
            raise TypeError("Can only merge with another TikTok profile.")
        combined_username = f"{self._username}+{other._username}"
        combined_followers = self._followers + other._followers
        combined_videos = self._videos + other._videos
        combined_views = self._total_views + other._total_views
        return TikTok(combined_username, combined_followers, 
                     combined_videos, combined_views)

# Derived Snapchat class
class Snapchat(SocialMedia):
    
    def __init__(self, username: str, followers: int, snaps_sent: int, streak_days: int):
        super().__init__(username, followers)
        self._validate_nonnegative(snaps_sent, "snaps_sent")
        self._validate_nonnegative(streak_days, "streak_days")
        self._snaps_sent = snaps_sent
        self._streak_days = streak_days
        self._snap_history = []

    def send_snap(self, count: int = 1):
        self._validate_nonnegative(count, "snap count")
        self._snaps_sent += count
        self._snap_history.append(count)
        return self._snaps_sent

    def increase_streak(self):
        self._streak_days += 1
        return self._streak_days

    def reset_streak(self):
        self._streak_days = 0
        return self._streak_days

    def display(self):
        base = super().display()
        return (f"{base}, Snaps Sent: {self._snaps_sent}, "
                f"Streak: {self._streak_days} days")

    def __add__(self, other):
        if not isinstance(other, Snapchat):
            raise TypeError("Can only merge with another Snapchat profile.")
        combined_username = f"{self._username}+{other._username}"
        combined_followers = self._followers + other._followers
        combined_snaps = self._snaps_sent + other._snaps_sent
        combined_streak = max(self._streak_days, other._streak_days)
        return Snapchat(combined_username, combined_followers, 
                       combined_snaps, combined_streak)