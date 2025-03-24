#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int start, end;
};

bool compare(Activity a, Activity b) {
    return a.end < b.end;
}

int maxActivities(int n, int s[], int e[]) {
    if (n == 0) return 0;

    vector<Activity> activities;
    for (int i = 0; i < n; i++) {
        Activity act = {s[i], e[i]};  
        activities.push_back(act);
    }

    sort(activities.begin(), activities.end(), compare);

    int count = 1, lastEnd = activities[0].end;
    cout << "Selected activities:\n";
    cout << activities[0].start << " " << activities[0].end << endl;

    for (int i = 1; i < n; i++) {
        if (activities[i].start >= lastEnd) {
            cout << activities[i].start << " " << activities[i].end << endl;
            lastEnd = activities[i].end;
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    int s[n], e[n];
    cout << "Enter start and end times of each activity:\n";
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> e[i];
    }

    int result = maxActivities(n, s, e);
    cout << "Maximum number of activities: " << result << endl;

    return 0;
}
