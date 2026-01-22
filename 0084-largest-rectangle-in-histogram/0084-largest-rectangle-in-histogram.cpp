class Solution {
    vector<int> nSL(vector<int>& heights){
        stack<pair<int,int>> st; // {arr[i],i}
        vector<int> v;
        for(int i=0; i<heights.size(); i++){
            if(st.size() == 0)
                v.push_back(-1);
            else if(st.size() > 0 and st.top().first < heights[i])
                v.push_back(st.top().second);
            else if(st.size() > 0 and st.top().first >= heights[i]){
                while (st.size() > 0 and st.top().first >= heights[i])
                    st.pop();
                if(st.size() == 0)
                    v.push_back(-1);
                else
                    v.push_back(st.top().second);
            }
            st.push({heights[i], i});
        }
        return v;
    }
    vector<int> nSR(vector<int>& heights){
        stack<pair<int,int>> st; // {arr[i],i}
        vector<int> v;
        for(int i=heights.size()-1; i>=0; i--){
            if(st.size() == 0)
                v.push_back(heights.size());
            else if(st.size() > 0 and st.top().first < heights[i])
                v.push_back(st.top().second);
            else if(st.size() > 0 and st.top().first >= heights[i]){
                while (st.size() > 0 and st.top().first >= heights[i])
                    st.pop();
                if(st.size() == 0)
                    v.push_back(heights.size());
                else
                    v.push_back(st.top().second);
            }
            st.push({heights[i], i});
        }
        reverse(v.begin(),v.end());
        return v;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        // Nearest Smaller to left
        vector<int> left = nSL(heights);
        // Nearest Greater to right
        vector<int> right = nSR(heights);
        vector<int> width(heights.size());
        vector<int> area(heights.size());
        int maxArea = 0;
        for(int i=0; i<heights.size();i++){
            width[i] = right[i] - left[i] - 1;
        }
        for(int i=0; i<heights.size();i++){
            area[i] = width[i] * heights[i];
            maxArea = max(area[i], maxArea);
        }
        return maxArea;
        
    }
};