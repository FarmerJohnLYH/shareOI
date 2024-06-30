lclass Matrix {  
public:  
    LL val[maxn][maxn];  
    Matrix() {  
        memset(val, 0, sizeof(val));  
    }  
  
    Matrix operator*(const Matrix& c) const {  
        Matrix res;  
        for (int i = 0; i < n; ++i)  
            for (int j = 0; j < n; ++j)  
                for (int k = 0; k < n; ++k) {  
                    res.val[i][j] += val[i][k] * c.val[k][j];  
                    res.val[i][j] = (res.val[i][j] + MOD) % MOD; 
                }  
        return res;  
    }  
  
    Matrix& operator*=(const Matrix& c) {  
        *this = *this * c;  
        return *this;  
    }  
  
    Matrix Pow(LL k) { //返回one^k  
        Matrix res = Zero();  
        Matrix step = One();  
        while (k) {  
            if (k & 1)  
                res *= step;  
            k >>= 1;  
            step *= step;  
        }  
        return res;  
    }  
  
    Matrix Zero() const {  
        Matrix res;  
        for (int i = 0; i < maxn; ++i)  
            res.val[i][i] = 1;  
        return res;  
    }  
  
    Matrix One() const {  
        Matrix res;  
        res.val[0][0] = res.val[0][1] = 1;  
        res.val[n-1][n-1] = res.val[n-1][n-2] = 1;  
        for (int i = 1; i < n - 1; ++i) {  
            res.val[i][i-1] = res.val[i][i] = res.val[i][i + 1] = 1;  
        }  
        return res;  
    }  
};  