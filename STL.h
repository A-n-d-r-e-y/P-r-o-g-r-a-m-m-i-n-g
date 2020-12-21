class Eq {
    int _this;
public:
    Eq(int th) : _this(th) {}
    bool operator()(int i) {
        return i == _this;
    }
};