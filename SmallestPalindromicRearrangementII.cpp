class Solution {
    using ll = long long;
    using lll = __int128;
    static const ll CAP = (ll)4e18;

    static ll combCapped(ll n, ll r) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n - r) r = n - r;
        lll res = 1;
        for (ll i = 1; i <= r; i++) {
            res = res * (n - r + i);
            res /= i;
            if (res > (lll)CAP) return CAP + 1;
        }
        return (ll)res;
    }

    static ll multinomialCapped(array<int,26>& counts, int total) {
        lll result = 1;
        int remaining = total;
        for (int c = 0; c < 26; c++) {
            if (counts[c] == 0) continue;
            ll comb = combCapped(remaining, counts[c]);
            if (comb > CAP) return CAP + 1;
            result *= comb;
            remaining -= counts[c];
            if (result > (lll)CAP) return CAP + 1;
        }
        return (ll)result;
    }

public:
    string smallestPalindrome(string s, long long k) {
        int n = s.size();
        array<int,26> cnt{};
        for (char ch : s) cnt[ch - 'a']++;

        int half = n / 2;
        array<int,26> halfCnt{};
        int midChar = -1;
        for (int c = 0; c < 26; c++) {
            halfCnt[c] = cnt[c] / 2;
            if (cnt[c] % 2 == 1) midChar = c;
        }

        ll total = multinomialCapped(halfCnt, half);
        if (k > total) return "";

        string halfStr;
        int remaining = half;
        for (int pos = 0; pos < half; pos++) {
            for (int c = 0; c < 26; c++) {
                if (halfCnt[c] == 0) continue;
                halfCnt[c]--;
                ll cntPerm = multinomialCapped(halfCnt, remaining - 1);
                if (k <= cntPerm) {
                    halfStr.push_back('a' + c);
                    remaining--;
                    goto nextPos;
                } else {
                    k -= cntPerm;
                    halfCnt[c]++;
                }
            }
            nextPos:;
        }

        string rev = halfStr;
        reverse(rev.begin(), rev.end());
        string ans = halfStr;
        if (n % 2 == 1) ans.push_back('a' + midChar);
        ans += rev;
        return ans;
    }
};