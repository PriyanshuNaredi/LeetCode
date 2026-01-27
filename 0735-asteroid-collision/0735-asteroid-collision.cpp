class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int i = 0; i < asteroids.size(); i++) {

            // if asteroids[i] is +ve then we will directly add it to stack
            // Right-moving asteroid: no collision possible, add to stack
            if (asteroids[i] > 0)
                st.push(asteroids[i]);

            // if asteroids[i] is -ve then
            // Left-moving asteroid: check for collisions with right-moving
            // asteroids
            else {
                // until we found the +ve asteroids >= then current -ve we will
                // destroy while +ve asteroids/st.top() is less than -ve we
                // destroy the stored asteroids Destroy smaller right-moving
                // asteroids in the stack Continue until we find a larger or
                // equal right-moving asteroid, or run out
                while (st.size() > 0 and st.top() > 0 and
                       st.top() < abs(asteroids[i]))
                    st.pop();
                // if +ve and -ve asteroids is same then both asteroids will be
                // distroyed
                if (st.size() > 0 and st.top() == abs(asteroids[i]))
                    st.pop();
                // No collision occurs if:
                // 1. Stack is empty (no asteroids to collide with), OR
                // 2. Top asteroid is also left-moving (both move left, no collision)
                // if the stack is empty or stack already has -ve asteroids we
                // will add current
                else if (st.empty() or st.top() < 0)
                    st.push(asteroids[i]);
            }
        }
        vector<int> res(st.size());
        int i = st.size() - 1;

        while (!st.empty()) {
            res[i--] = st.top();
            st.pop();
        }
        return res;
    }
};
