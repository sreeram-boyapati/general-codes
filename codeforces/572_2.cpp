#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define  map_int_it map<int, int>::iterator
using namespace std;
typedef pair<int, int> my_pair;

bool cmp(const my_pair& a, const my_pair& b){
    return a.first > b.first;
}

bool opp_cmp(const my_pair& a, const my_pair& b){
    return a.first < b.first;
}

int main(){
    int n, m;
    cin>>n>>m;
    map<int, int> bprice_quantity;
    map<int, int> sprice_quantity;
    for(int i=0; i<n; i++){
        char s_or_b;
        int price, volume;
        cin>>s_or_b>>price>>volume;
        if(s_or_b == 'B')
            if(bprice_quantity.find(price) != bprice_quantity.end())
                bprice_quantity[price] += volume;
            else
                bprice_quantity[price] = volume;
        else
            if(sprice_quantity.find(price) != sprice_quantity.end())
                sprice_quantity[price] += volume;
            else
                sprice_quantity[price] = volume;
    }
    vector<my_pair> buy_aggr;
    vector<my_pair> sell_aggr;
    vector<my_pair> revised_sell_aggr;
    for(map_int_it it = bprice_quantity.begin(); it != bprice_quantity.end(); it++)
        buy_aggr.push_back(make_pair(it->first, it->second));

    for(map_int_it it = sprice_quantity.begin(); it != sprice_quantity.end(); it++)
        sell_aggr.push_back(make_pair(it->first, it->second));

    sort(buy_aggr.begin(), buy_aggr.end(), cmp);
    sort(sell_aggr.begin(), sell_aggr.end(), opp_cmp);
    for(int i=0; i<m && i<sell_aggr.size(); i++){
        revised_sell_aggr.push_back(sell_aggr[i]);
    }

    sort(revised_sell_aggr.begin(), revised_sell_aggr.end(), cmp);
    for(int i=0; i<m && i<sell_aggr.size(); i++){
        pair<int, int> model = revised_sell_aggr[i];
        cout<<"S "<<model.first<<" "<<model.second<<endl;
    }
    for(int i=0; i<m && i<buy_aggr.size(); i++){
        pair<int, int> model = buy_aggr[i];
        cout<<"B "<<model.first<<" "<<model.second<<endl;
    }
    return 0;
}
