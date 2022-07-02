#define ll long long
class Solution {
public:
	const int mod = 1e9+7;
	int maxArea(int h, int w, vector<int>& horizontal, vector<int>& vertical) {
		horizontal.insert(horizontal.begin() , 0);
		vertical.insert(vertical.begin() , 0);
		horizontal.push_back(h);
		vertical.push_back(w);
		int n = horizontal.size();
		int m = vertical.size();
		sort(horizontal.begin() , horizontal.end());
		sort(vertical.begin() , vertical.end());

		ll max_h = 0;
		ll max_w = 0;
		ll prev_h = horizontal[1] - horizontal[0];
		max_h = prev_h;
		for(int i=1;i<n-1;i++){
			if(max_h < (horizontal[i+1] - horizontal[i])){
				max_h = horizontal[i+1] - horizontal[i];
			}
		}
		max_w = vertical[1] - vertical[0];
		for(int i=1;i<m-1;i++){
			if(max_w < (vertical[i+1] - vertical[i])){
				max_w = vertical[i+1] - vertical[i];
			}
		}
		return (max_h *1ll*max_w)%mod;
	}
};
// If we had only horizontalCuts and we needed to find the max area of cake then problem would boil down to finding the max consecutive diff betwwen two hCuts * width that will be the max area of cake.
// **And one more point to note is that the max area will be contributed by cuts who have maximum difference in between them.**
// So taking the similar analogy we can find the max_h i.e maximum horizontal diff between two cuts and max_w i.e maximum vertical diff between two cuts.
// and our ans will be multiplication of both.
