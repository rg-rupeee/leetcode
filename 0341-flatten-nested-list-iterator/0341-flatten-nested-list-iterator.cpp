/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> flatList;
    vector<int>::iterator it;
    
    void flatten(vector<NestedInteger> &nestedList){
        for(auto &ni: nestedList){
            if(ni.isInteger()){
                flatList.push_back(ni.getInteger());
            }
            else{
                flatten(ni.getList());
            }
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
        it = flatList.begin();
    }
    
    int next() {
        return *it++;
    }
    
    bool hasNext() {
       return it != flatList.end();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */