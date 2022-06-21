#include "ComputeN.h"

void ComputeN::init(long double R, long double P, long double T, long double V)
{
    m_R = R;
    m_P = P;
    m_T = T;
    m_V = V;
}

long double ComputeN::compute_n()
{
    long double N = 0;
    N = (m_P * m_V) / (m_R * m_T);
    std::cout << N << std::endl;
    return N;
}
