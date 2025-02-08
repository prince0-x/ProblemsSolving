class NumberContainers {
public:
    unordered_map<int,set<int>>nti;
    unordered_map<int,int>itn;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(itn.find(index)!=itn.end())
        {
            int previ =itn[index];
            nti[previ].erase(index);
            if(nti[previ].empty())
            {
                nti.erase(previ);
            }
        }
        itn[index]=number;
        nti[number].insert(index);
    }
    
    int find(int number) {
        if(nti.find(number)!=nti.end())
        {
            return *nti[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */