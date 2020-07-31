int trie[10000006][2],f[10000006],node=1,bits=30;
void add(int x){
    int cur=1,cnt=0;
    while(cnt<=bits){
        int b=(x>>(bits-cnt))&1;
        if(trie[cur][b]){
            cur=trie[cur][b];
            f[cur]++;
        }
        else{
            trie[cur][b]=++node;
            cur=node;
            f[cur]++;
        }
        cnt++;
    }
}
int query(int x){
    int cur=1,cnt=0,ans=0;
    while(cnt<=bits){
        int b=(x>>(bits-cnt))&1;
        if(trie[cur][b] && f[trie[cur][b]]){
            cur=trie[cur][b];
        }
        else{
            cur=trie[cur][!b];
            ans+=(1<<(bits-cnt));
        }
        cnt++;
    }
    return ans;
}
void del(int x){
    int cur=1,cnt=0;
    while(cnt<=bits){
        int b=(x>>(bits-cnt))&1;
        cur=trie[cur][b];
        f[cur]--;
        cnt++;
    }
}