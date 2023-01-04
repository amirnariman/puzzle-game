polynomial operator - (polynomial a)
    {
        polynomial b;

        b.A= A - a.A;
        b.B= B - a.B;

        return b;
    }