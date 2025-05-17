class DSU {
public:
    vector<int>par;
    vector<int>size;
    int components;
    DSU(int n)
    {
        par.resize(n+1);
        size.resize(n+1,1);
        for(int i = 1; i<=n; i++) 
        {
            par[i]=i;
        }
        components=n;
    }
    int getRoot(int i)
    {
		if (par[i] != i)
			par[i] = getRoot(par[i]); // Path compression
		return par[i];
    }
	
    int find(int i,int j)
    {
        return getRoot(i)==getRoot(j);
    }
	
	//Union by Size
    void Union(int i,int j)
    {
        if(find(i,j))
        {
            return;
        }
        int rooti=getRoot(i);
        int rootj=getRoot(j);
        int sizei=size[rooti];
        int sizej=size[rootj];
        if(sizei>sizej)
        {
            par[rootj]=rooti;
            size[rooti]+=sizej;
        }
        else
        {
			par[rooti]=rootj;
            size[rootj]+=sizei;  
        }
        components--;
    }
     bool isSingle() {
            return components == 1;
        }
    };