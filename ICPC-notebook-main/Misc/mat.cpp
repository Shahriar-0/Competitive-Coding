struct Mat{
    int m[K][K];
    Mat(int diag = -1){
        ms(m , 0);
        if(diag==0)for(int i = 0 ; i < K ; i ++)m[i][i] = 1;
        if(diag>0)for(int i = 0 ; i < diag ; i ++)m[i][i+1]=1;
    }
    Mat operator* (const Mat &b) const{
        Mat c = Mat();
        for(int i = 0 ; i < K ; i ++)
            for(int k = 0 ; k < K ; k ++)
                for(int j = 0 ; j < K ; j ++)
                    c.m[i][j] = (ll(c.m[i][j]) + ll(m[i][k]) * b.m[k][j])%mod;
        return(c);
    }
};
Mat pw(Mat a, ll b){Mat res(0);while(b){if(b&1){res=(a*res);}a=(a*a);b>>=1;}return(res);}