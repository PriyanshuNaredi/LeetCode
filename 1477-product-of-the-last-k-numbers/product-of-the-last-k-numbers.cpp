class ProductOfNumbers {
public:
    vector<int> product={1};
    int n=1;
    ProductOfNumbers(){
    }
    // CodeAndComplexity Reel for the Algo
    // store the product of two numbers in an vector
    // handle edge case when 0 come
    void add(int num) {
        if (num==0) {
            product={1};
            n=1;
        }
        else{
            product.push_back(product[n++-1]*num);
        }
    }
    
    int getProduct(int k) {
        if (n<=k) return 0;
        return product[n-1]/product[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */