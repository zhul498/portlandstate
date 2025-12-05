# Lian Zhu
# CS 302
# bst.py - Program #5

from socialmedia import SocialMedia

class Node:
    
    def __init__(self, data):
        self._data = data
        self._left = None
        self._right = None
    
    def get_data(self):
        return self._data
    
    def set_data(self, data):
        self._data = data
    
    def get_left(self):
        return self._left
    
    def set_left(self, node):
        self._left = node
    
    def get_right(self):
        return self._right
    
    def set_right(self, node):
        self._right = node


class BST:
    
    def __init__(self):
        self._root = None
        self._count = 0
    
    def insert(self, profile):
        if not isinstance(profile, SocialMedia):
            raise TypeError("Can only insert SocialMedia profiles")
        self._root = self._insert_recursive(self._root, profile)
    
    def _insert_recursive(self, node, profile):
        if node is None:
            self._count += 1
            return Node(profile)
        
        if profile._username < node.get_data()._username:
            node.set_left(self._insert_recursive(node.get_left(), profile))
        elif profile._username > node.get_data()._username:
            node.set_right(self._insert_recursive(node.get_right(), profile))
        else:
            node.set_data(profile)
        
        return node
    
    def retrieve(self, username):
        return self._retrieve_recursive(self._root, username)
    
    def _retrieve_recursive(self, node, username):
        if node is None:
            return None
        
        if username == node.get_data()._username:
            return node.get_data()
        elif username < node.get_data()._username:
            return self._retrieve_recursive(node.get_left(), username)
        else:
            return self._retrieve_recursive(node.get_right(), username)
    
    def display_all(self):
        if self._root is None:
            print("No profiles in the system.")
            return
        print("\n=== All Profiles (Alphabetical Order) ===")
        self._display_recursive(self._root)
        print()
    
    def _display_recursive(self, node):
        if node is None:
            return
        
        self._display_recursive(node.get_left())
        print(node.get_data().display())
        self._display_recursive(node.get_right())
    
    def remove(self, username):
        if self._root is None:
            raise ValueError("Cannot remove from empty tree")
        self._root = self._remove_recursive(self._root, username)
    
    def _remove_recursive(self, node, username):
        if node is None:
            raise ValueError(f"Profile '{username}' not found")
        
        if username < node.get_data()._username:
            node.set_left(self._remove_recursive(node.get_left(), username))
        elif username > node.get_data()._username:
            node.set_right(self._remove_recursive(node.get_right(), username))
        else:
            if node.get_left() is None and node.get_right() is None:
                self._count -= 1
                return None
            elif node.get_left() is None:
                self._count -= 1
                return node.get_right()
            elif node.get_right() is None:
                self._count -= 1
                return node.get_left()
            else:
                successor = self._find_min(node.get_right())
                node.set_data(successor.get_data())
                node.set_right(self._remove_recursive(node.get_right(), successor.get_data()._username))
        
        return node
    
    def _find_min(self, node):
        if node.get_left() is None:
            return node
        return self._find_min(node.get_left())
    
    def get_count(self):
        return self._count
    
    def is_empty(self):
        return self._root is None
    
    def display_by_platform(self, platform_type):
        if self._root is None:
            print("No profiles in the system.")
            return
        print(f"\n=== {platform_type} Profiles ===")
        count = self._display_by_platform_recursive(self._root, platform_type)
        if count == 0:
            print(f"No {platform_type} profiles found.")
        print()
    
    def _display_by_platform_recursive(self, node, platform_type):
        if node is None:
            return 0
        
        count = 0
        count += self._display_by_platform_recursive(node.get_left(), platform_type)
        
        if type(node.get_data()).__name__ == platform_type:
            print(node.get_data().display())
            count += 1
        
        count += self._display_by_platform_recursive(node.get_right(), platform_type)
        return count
    
    def get_all_profiles(self):
        profiles = []
        self._collect_profiles_recursive(self._root, profiles)
        return profiles
    
    def _collect_profiles_recursive(self, node, profiles):
        if node is None:
            return
        
        self._collect_profiles_recursive(node.get_left(), profiles)
        profiles.append(node.get_data())
        self._collect_profiles_recursive(node.get_right(), profiles)

class SocialMediaApp:
    
    def __init__(self):
        self._bst = BST()
    
    def run(self):
        print("\n" + "="*50)
        print("  Social Media Analytics Tool")
        print("  Beginner-Friendly Platform Analysis")
        print("="*50)
        
        while True:
            self._display_menu()
            
            try:
                choice = input("\nEnter choice: ").strip()
                
                if choice == "1":
                    self._add_profile()
                elif choice == "2":
                    self._display_profile()
                elif choice == "3":
                    self._update_stats()
                elif choice == "4":
                    self._compare_profiles()
                elif choice == "5":
                    self._merge_profiles()
                elif choice == "6":
                    self._display_all_profiles()
                elif choice == "7":
                    self._display_by_platform()
                elif choice == "8":
                    self._remove_profile()
                elif choice == "0":
                    print("\nThank you for using Social Media Analytics Tool!")
                    break
                else:
                    print("\nInvalid choice. Please enter a number from the menu.")
            
            except Exception as e:
                print(f"\nError: {e}")
    
    def _display_menu(self):
        print("\n" + "-"*50)
        print("MENU OPTIONS:")
        print("-"*50)
        print("(1) Add a Profile")
        print("(2) Display Profile Analytics")
        print("(3) Update Platform Stats")
        print("(4) Compare Profiles (<)")
        print("(5) Merge Stats (+)")
        print("(6) Display All Profiles (BST Traversal)")
        print("(7) Display Profiles by Platform")
        print("(8) Remove a Profile")
        print("(0) Exit")
        print("-"*50)
    
    def _add_profile(self):
        print("\n--- Add New Profile ---")
        
        platform = self._get_valid_platform()
        username = self._get_nonempty_input("Enter username: ")
        
        existing = self._bst.retrieve(username)
        if existing is not None:
            print(f"Profile '{username}' already exists!")
            return
        
        followers = self._get_nonnegative_int("Enter followers: ")
        
        try:
            if platform == "LinkedIn":
                connections = self._get_nonnegative_int("Enter connections: ")
                posts = self._get_nonnegative_int("Enter posts: ")
                profile = LinkedIn(username, followers, connections, posts)
            
            elif platform == "TikTok":
                videos = self._get_nonnegative_int("Enter videos: ")
                total_views = self._get_nonnegative_int("Enter total views: ")
                profile = TikTok(username, followers, videos, total_views)
            
            elif platform == "Snapchat":
                snaps_sent = self._get_nonnegative_int("Enter snaps sent: ")
                streak_days = self._get_nonnegative_int("Enter streak days: ")
                profile = Snapchat(username, followers, snaps_sent, streak_days)
            
            self._bst.insert(profile)
            print(f"\n{platform} profile '{username}' added successfully!")
        
        except ValueError as e:
            print(f"\nError creating profile: {e}")
    
    def _display_profile(self):
        print("\n--- Display Profile Analytics ---")
        
        if self._bst.is_empty():
            print("No profiles in the system.")
            return
        
        username = self._get_nonempty_input("Enter username to display: ")
        profile = self._bst.retrieve(username)
        
        if profile is None:
            print(f"Profile '{username}' not found.")
        else:
            print("\n" + "="*50)
            print(profile.display())
            print("="*50)
    
    def _update_stats(self):
        print("\n--- Update Platform Stats ---")
        
        if self._bst.is_empty():
            print("No profiles in the system.")
            return
        
        username = self._get_nonempty_input("Enter username: ")
        profile = self._bst.retrieve(username)
        
        if profile is None:
            print(f"Profile '{username}' not found.")
            return
        
        platform_type = type(profile).__name__
        print(f"\nUpdating {platform_type} profile: {username}")
        print("\nUpdate Options:")
        print("(1) Update followers")
        
        if platform_type == "LinkedIn":
            print("(2) Add connection")
            print("(3) Add post")
        elif platform_type == "TikTok":
            print("(2) Add video")
        elif platform_type == "Snapchat":
            print("(2) Send snap")
            print("(3) Increase streak")
            print("(4) Reset streak")
        
        choice = input("\nEnter choice: ").strip()
        
        try:
            if choice == "1":
                new_followers = self._get_nonnegative_int("Enter new follower count: ")
                profile.update_followers(new_followers)
                print("Followers updated!")
            
            elif choice == "2":
                if platform_type == "LinkedIn":
                    profile.add_connection()
                    print("Connection added!")
                elif platform_type == "TikTok":
                    views = self._get_nonnegative_int("Enter video views: ")
                    profile.add_video(views)
                    print("Video added!")
                elif platform_type == "Snapchat":
                    count = self._get_nonnegative_int("Enter number of snaps (default 1): ", default=1)
                    profile.send_snap(count)
                    print("Snap(s) sent!")
            
            elif choice == "3":
                if platform_type == "LinkedIn":
                    title = input("Enter post title (or press Enter for default): ").strip()
                    if title:
                        profile.add_post(title)
                    else:
                        profile.add_post()
                    print("Post added!")
                elif platform_type == "Snapchat":
                    profile.increase_streak()
                    print("Streak increased!")
            
            elif choice == "4" and platform_type == "Snapchat":
                profile.reset_streak()
                print("Streak reset!")
            
            else:
                print("Invalid choice for this platform.")
        
        except ValueError as e:
            print(f"Error: {e}")
    
    def _compare_profiles(self):
        print("\n--- Compare Profiles (<) ---")
        
        if self._bst.is_empty():
            print("No profiles in the system.")
            return
        
        username1 = self._get_nonempty_input("Enter first username: ")
        username2 = self._get_nonempty_input("Enter second username: ")
        
        profile1 = self._bst.retrieve(username1)
        profile2 = self._bst.retrieve(username2)
        
        if profile1 is None:
            print(f"Profile '{username1}' not found.")
            return
        if profile2 is None:
            print(f"Profile '{username2}' not found.")
            return
        
        print("\n" + "="*50)
        print(f"Profile 1: {profile1.display()}")
        print(f"Profile 2: {profile2.display()}")
        print("="*50)
        
        if profile1 < profile2:
            print(f"\n'{username1}' has fewer followers than '{username2}'")
        elif profile2 < profile1:
            print(f"\n'{username2}' has fewer followers than '{username1}'")
        else:
            print(f"\nBoth profiles have the same number of followers!")
    
    def _merge_profiles(self):
        print("\n--- Merge Stats (+) ---")
        
        if self._bst.is_empty():
            print("No profiles in the system.")
            return
        
        username1 = self._get_nonempty_input("Enter first username: ")
        username2 = self._get_nonempty_input("Enter second username: ")
        
        profile1 = self._bst.retrieve(username1)
        profile2 = self._bst.retrieve(username2)
        
        if profile1 is None:
            print(f"Profile '{username1}' not found.")
            return
        if profile2 is None:
            print(f"Profile '{username2}' not found.")
            return
        
        platform1 = type(profile1).__name__
        platform2 = type(profile2).__name__
        
        if platform1 != platform2:
            print(f"Cannot merge different platforms ({platform1} and {platform2})")
            return
        
        try:
            merged = profile1 + profile2
            print("\n" + "="*50)
            print("Merged Profile:")
            print(merged.display())
            print("="*50)
            
            save = input("\nSave merged profile? (y/n): ").strip().lower()
            if save == 'y':
                self._bst.insert(merged)
                print("Merged profile saved!")
        
        except TypeError as e:
            print(f"Error merging profiles: {e}")
    
    def _display_all_profiles(self):
        print("\n--- All Profiles (BST In-Order Traversal) ---")
        self._bst.display_all()
        print(f"Total profiles: {self._bst.get_count()}")
    
    def _display_by_platform(self):
        print("\n--- Display by Platform ---")
        
        if self._bst.is_empty():
            print("No profiles in the system.")
            return
        
        platform = self._get_valid_platform()
        self._bst.display_by_platform(platform)
    
    def _remove_profile(self):
        print("\n--- Remove Profile ---")
        
        if self._bst.is_empty():
            print("No profiles in the system.")
            return
        
        username = self._get_nonempty_input("Enter username to remove: ")
        
        profile = self._bst.retrieve(username)
        if profile is None:
            print(f"Profile '{username}' not found.")
            return
        
        confirm = input(f"Are you sure you want to remove '{username}'? (y/n): ").strip().lower()
        if confirm == 'y':
            try:
                self._bst.remove(username)
                print(f"Profile '{username}' removed successfully!")
            except ValueError as e:
                print(f"Error: {e}")
    
    def _get_valid_platform(self):
        while True:
            print("\nPlatforms: LinkedIn, TikTok, Snapchat")
            platform = input("Select platform: ").strip()
            
            if platform in ["LinkedIn", "TikTok", "Snapchat"]:
                return platform
            else:
                print("Invalid platform. Choose: LinkedIn, TikTok, or Snapchat")
    
    def _get_nonempty_input(self, prompt):
        while True:
            value = input(prompt).strip()
            if value:
                return value
            print("Input cannot be empty. Please try again.")
    
    def _get_nonnegative_int(self, prompt, default=None):
        while True:
            try:
                value = input(prompt).strip()
                if not value and default is not None:
                    return default
                num = int(value)
                if num < 0:
                    print("Value must be non-negative.")
                    continue
                return num
            except ValueError:
                print("Please enter a valid integer.")