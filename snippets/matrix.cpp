struct Matrix {
    vector<vl> mat;
    lli n, m;

    Matrix(lli n, lli m) {
        this->n = n;
        this->m = m;
        mat.assign(n, vl(m, 0));
    }

    static Matrix identity(lli n) {
        Matrix I(n, n);
        for (lli i = 0; i < n; i++) I.mat[i][i] = 1;
        return I;
    }

    Matrix operator*(const Matrix &other) const {
        Matrix res(n, other.m);
        for (lli i = 0; i < n; i++) {
            for (lli k = 0; k < m; k++) {
                for (lli j = 0; j < other.m; j++) {
                    res.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
        return res;
    }

    Matrix power(lli p) const {
        Matrix res = identity(n);
        Matrix base = *this;
        while (p) {
            if (p & 1) res = res * base;
            base = base * base;
            p >>= 1;
        }
        return res;
    }
};
