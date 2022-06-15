#include <QCoreApplication>
#include "ParseX.h"
#include "ParseA.h"
#include "MergeXA.h"
#include "ComputeQevj.h"
#include "ComputeQ.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int type = 0;
    std::cout << "input number: type=1->x & a & Qevj , type=2-> Q" << std::endl;
    std::cin >> type;
    if(type==1){
        //compute x & a & Qevj
        std::cout << "input: url_1 (example: C:/1.txt)" << std::endl;
        char x_a_1_url[1024] = "";
        std::cin >> x_a_1_url;
        std::cout << "input: url_2 (example: C:/2.txt)" << std::endl;
        char x_a_2_url[1024] = "";
        std::cin >> x_a_2_url;
        std::cout << "input: url_a (example: C:/Aul.txt)" << std::endl;
        char x_a_a_url[1024] = "";
        std::cin >> x_a_a_url;
        //compute x & a & Qevj
        ComputeQevj m_pComputeQevj = ComputeQevj();
        m_pComputeQevj.init(MergeXA().Merge(ParseX().XVector("BASIC", 0, x_a_1_url, "EXC", 15000, x_a_2_url), ParseA().AVector(x_a_a_url)),
                            6.63 * pow(10, -34),               // h 常量
                            2.99792458 * pow(10, 10),          // c 常量
                            15000,                            // K 常量
                            (1.38 * pow(10, -23)),           // Tex 常量
                            (1.38 * pow(10, -23)),           // Tvib 常量
                            (1.38 * pow(10, -23)),           // Trot 常量
                            6,                               // gne   偶数时的值
                            3,                               // gno   奇数时的值
                            1);
        m_pComputeQevj.computeQevj_s();
    } else if(type == 2){
        // compute Q
        std::cout << "input: url (example: c:/xxx.txt)" << std::endl;
        char q_url[1024] = "";
        std::cin >> q_url;
        //compute Q
        ComputeQ m_qCompute = ComputeQ();
        m_qCompute.init(
                    ParseX().ParseStr2VJ("segma", 0, q_url), // q_name 名称, q_t 跃迁, q_url 文件
                    6.63 * pow(10, -34),                   // h 常量
                    2.99792458 * pow(10, 10),              // c 常量
                    15000,                            // K 常量
                    (1.38 * pow(10, -23)),           // Tex 常量
                    (1.38 * pow(10, -23)),           // Tvib 常量
                    (1.38 * pow(10, -23)),           // Trot 常量
                    6,                                     // gne   偶数时的值
                    3,                                     // gno   奇数时的值
                    1);                                    // gbase 倍数
        m_qCompute.sumQ();
    }
    system("pause");
    return a.exec();
}
