// class Solution {
// public:
//     int calPoints(vector<string>& operations) {
//         stack<int>s;
//         for(int i=0;i<operations.size();i++)
//         {
//             if(operations[i]=="C")
//             {
//                 s.pop();
//             }
//             else if(operations[i]=="D")
//             {
//                 int a=s.top();
//                 s.push(a*2);
//             }
//             else if(operations[i]=="+")
//             {
//                 int a=s.top();
//                 s.pop();
//                 int b=s.top();
//                 s.push(a);
//                 s.push(a+b);
//             }
//             else{
//                 s.push(stoi(operations[i]));
//             }
//         }
//         int ans=0;
//         if(!s.empty())
//         {
//             while(!s.empty())
//             {
//                 ans=ans+s.top();
//                 s.pop();
//             }
//             return ans;
//         }
//         else{
//             return 0;
//         }
//     }
// };
class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> scores;
        int sum = 0;

        for (const string& op : ops) {
            if (op == "+") {
                int prev1 = scores.top();
                scores.pop();
                int prev2 = scores.top();
                scores.push(prev1);
                scores.push(prev1 + prev2);
            } else if (op == "D") {
                scores.push(scores.top() * 2);
            } else if (op == "C") {
                scores.pop();
            } else {
                scores.push(stoi(op));
            }
        }

        while (!scores.empty()) {
            sum += scores.top();
            scores.pop();
        }

        return sum;
    }
};