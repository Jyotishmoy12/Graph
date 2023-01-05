class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
     unordered_set<string>bankset(bank.begin(), bank.end()); //quick access
        unordered_set<string>visit;
        queue<string>que;
        que.push(startGene);
        visit.insert(startGene);
        int level=0;
        while(!que.empty()){
            int n=que.size();
            while(n--){
                string curr=que.front();
                que.pop();
                if(curr==endGene) //reached level
                    return level;
                for(char ch:"ACGT"){
                    for(int i=0;i<curr.length();i++){
                        string neighbour=curr;
                        neighbour[i]=ch; //first try with A then c then G then T
                        if(visit.find(neighbour)==visit.end() && bankset.find(neighbour)!=bankset.end()){
                            visit.insert(neighbour);
                            que.push(neighbour);
                        }
                        
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
