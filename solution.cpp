#include <iostream>
#include <string>

using namespace std;

int longest_subword(string word_1, int w1_p, int w1_q, string word_2, int w2_p, int w2_q){
    int result=0;
    while(w1_p<=w1_q && w2_p<=w2_q){
        if(word_1[w1_p] == word_2[w2_p]){
            result++;
            w1_p++;
            w2_p++;
        }
        else{
            return result + max(
                longest_subword(word_1, w1_p+1, w1_q,
                                word_2, w2_p, w2_q),
                longest_subword(word_1, w1_p, w1_q,
                                word_2, w2_p+1, w2_q));
        }
    }
    return result;
}

int main(){
    int q;
    cin>>q;
    while(q--){
        int w1_len, w2_len;
        string word_1, word_2;
        cin>>w1_len;
        cin>>word_1;
        cin>>w2_len;
        cin>>word_2;
        cout<<longest_subword(word_1, 0, w1_len-1, word_2, 0, w2_len-1)<<endl;
    }
    return 0;
}