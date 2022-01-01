// Koray Ercan
// 1306190070
// Date:
// Development Environment: Code::Blocks 17.12

#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <fstream>

using namespace std;

template <typename T>
struct KeyValue {
    string name;
    T value;
};

vector <KeyValue<double> > vec_of_doubles;

string removeSpaces (string line){
    line.erase(remove(line.begin(),line.end(),' '),line.end());
    return line;
}
string removebrackets(string line){
    line.erase(remove(line.begin(),line.end(),')'),line.end());
    line.erase(remove(line.begin(),line.end(),'('),line.end());
    return line;
}
bool check (string ercan){
    for(int i=0;i<ercan.size();i++){
        if(ercan[i]=='/'||ercan[i]=='*'||ercan[i]=='-'||ercan[i]=='+'){
            return true;
        }
    }
    return false;
}
double calculatoroparator(string rightside){
    int konum;
    double soldeger;
    double sagdeger;
    bool solbulundu = false;
    bool sagbulundu = false;
    if(rightside.find("IF") != std::string::npos){
        int konumIF=rightside.find("IF")+1;
        int konumTHEN=rightside.find("THEN")+3;
        int konumELSE=rightside.find("ELSE")+3;
        string kosul=rightside.substr(konumIF+1,konumTHEN-(konumIF+1)-3);
        string dogruysa=rightside.substr(konumTHEN+1,konumELSE-(konumTHEN+1)-3);
        string yanlissa=rightside.substr(konumELSE+1);
        string kosulop;
        if(kosul.find("!=")!= std::string::npos){kosulop="!=";}
        else if(kosul.find("==")!= std::string::npos){kosulop="==";}
        else if(kosul.find(">=")!= std::string::npos){kosulop=">=";}
        else if(kosul.find("<=")!= std::string::npos){kosulop="<=";}
        else if(kosul.find(">")!= std::string::npos){kosulop=">";}
        else if(kosul.find("<")!= std::string::npos){kosulop="<";}
        if(kosul.find(kosulop)!= std::string::npos){
            konum=kosul.find(kosulop);
            string sol = kosul.substr(0,konum);
            string sag = kosul.substr(konum+1);
            for(int i = 0;i<vec_of_doubles.size();i++){
                if(vec_of_doubles[i].name == sol){
                    soldeger = vec_of_doubles[i].value;
                    solbulundu = true;
                }
                if(vec_of_doubles[i].name == sag){
                    sagdeger = vec_of_doubles[i].value;
                    sagbulundu = true;
                }
            }
            if (!solbulundu){
                //soldeger = stod(sol);
                stringstream koray(sol);
                koray >> soldeger;
            }
            if(!sagbulundu){
                //sagdeger = stod(sag);
                stringstream koray(sag);
                koray >> sagdeger;
            }
            if(check(sol)){
                soldeger=calculatoroparator(sol);
            }
            if(check(sag)){
                sagdeger=calculatoroparator(sag);
            }
            if(kosulop=="<"){
                if(soldeger < sagdeger){
                    for(int i = 0;i<vec_of_doubles.size();i++){
                        if(vec_of_doubles[i].name == dogruysa){
                            double kosuldeger = vec_of_doubles[i].value;
                            return kosuldeger;
                        }
                    }
                }
                else{
                    for(int i = 0;i<vec_of_doubles.size();i++){
                        if(vec_of_doubles[i].name == yanlissa){
                            double kosuldeger = vec_of_doubles[i].value;
                            return kosuldeger;
                        }
                    }
                }
            }
            else if(kosulop==">"){
                if(soldeger > sagdeger){
                    for(int i = 0;i<vec_of_doubles.size();i++){
                        if(vec_of_doubles[i].name == dogruysa){
                            double kosuldeger = vec_of_doubles[i].value;
                            return kosuldeger;
                        }
                    }
                }
                else{
                    for(int i = 0;i<vec_of_doubles.size();i++){
                        if(vec_of_doubles[i].name == yanlissa){
                            double kosuldeger = vec_of_doubles[i].value;
                            return kosuldeger;
                        }
                    }
                }
            }
            /* kucuk esit */
            else if(kosulop=="<="){
                konum=kosul.find(kosulop);
                string sol = kosul.substr(0,konum);
                string sag = kosul.substr(konum+2);
                for(int i = 0;i<vec_of_doubles.size();i++){
                    if(vec_of_doubles[i].name == sol){
                        soldeger = vec_of_doubles[i].value;
                        solbulundu = true;
                    }
                    if(vec_of_doubles[i].name == sag){
                        sagdeger = vec_of_doubles[i].value;
                        sagbulundu = true;
                    }
                }
                if (!solbulundu){
                    //soldeger = stod(sol);
                    stringstream koray(sol);
                    koray >> soldeger;
                }
                if(!sagbulundu){
                    //sagdeger = stod(sag);
                    stringstream koray(sag);
                    koray >> sagdeger;
                }
                if(check(sol)){
                    soldeger=calculatoroparator(sol);
                }
                if(check(sag)){
                    sagdeger=calculatoroparator(sag);
                }
                if(soldeger <= sagdeger){
                    for(int i = 0;i<vec_of_doubles.size();i++){
                        if(vec_of_doubles[i].name == dogruysa){
                            double kosuldeger = vec_of_doubles[i].value;
                            return kosuldeger;
                        }
                    }
                }
                else{
                    for(int i = 0;i<vec_of_doubles.size();i++){
                        if(vec_of_doubles[i].name == yanlissa){
                            double kosuldeger = vec_of_doubles[i].value;
                            return kosuldeger;
                        }
                    }
                }
            }
            /* buyuk esit */
            else if(kosulop==">="){
                konum=kosul.find(kosulop);
                string sol = kosul.substr(0,konum);
                string sag = kosul.substr(konum+2);
                for(int i = 0;i<vec_of_doubles.size();i++){
                    if(vec_of_doubles[i].name == sol){
                        soldeger = vec_of_doubles[i].value;
                        solbulundu = true;
                    }
                    if(vec_of_doubles[i].name == sag){
                        sagdeger = vec_of_doubles[i].value;
                        sagbulundu = true;
                    }
                }
                if (!solbulundu){
                    //soldeger = stod(sol);
                    stringstream koray(sol);
                    koray >> soldeger;
                }
                if(!sagbulundu){
                    //sagdeger = stod(sag);
                    stringstream koray(sag);
                    koray >> sagdeger;
                }
                if(check(sol)){
                    soldeger=calculatoroparator(sol);
                }
                if(check(sag)){
                    sagdeger=calculatoroparator(sag);
                }
                if(soldeger >= sagdeger){
                    for(int i = 0;i<vec_of_doubles.size();i++){
                        if(vec_of_doubles[i].name == dogruysa){
                            double kosuldeger = vec_of_doubles[i].value;
                            return kosuldeger;
                        }
                    }
                }
                else{
                    for(int i = 0;i<vec_of_doubles.size();i++){
                        if(vec_of_doubles[i].name == yanlissa){
                            double kosuldeger = vec_of_doubles[i].value;
                            return kosuldeger;
                        }
                    }
                }
            }
            /* esit */
            else if(kosulop=="=="){
                konum=kosul.find(kosulop);
                string sol = kosul.substr(0,konum);
                string sag = kosul.substr(konum+2);
                for(int i = 0;i<vec_of_doubles.size();i++){
                    if(vec_of_doubles[i].name == sol){
                        soldeger = vec_of_doubles[i].value;
                        solbulundu = true;
                    }
                    if(vec_of_doubles[i].name == sag){
                        sagdeger = vec_of_doubles[i].value;
                        sagbulundu = true;
                    }
                }
                if (!solbulundu){
                    //soldeger = stod(sol);
                    stringstream koray(sol);
                    koray >> soldeger;
                }
                if(!sagbulundu){
                    //sagdeger = stod(sag);
                    stringstream koray(sag);
                    koray >> sagdeger;
                }
                if(check(sol)){
                    soldeger=calculatoroparator(sol);
                }
                if(check(sag)){
                    sagdeger=calculatoroparator(sag);
                }
                if(soldeger == sagdeger){
                    for(int i = 0;i<vec_of_doubles.size();i++){
                        if(vec_of_doubles[i].name == dogruysa){
                            double kosuldeger = vec_of_doubles[i].value;
                            return kosuldeger;
                        }
                    }
                }
                else{
                    for(int i = 0;i<vec_of_doubles.size();i++){
                        if(vec_of_doubles[i].name == yanlissa){
                            double kosuldeger = vec_of_doubles[i].value;
                            return kosuldeger;
                        }
                    }
                }
            }
            /*esit degil*/
            else if(kosulop=="!="){
                konum=kosul.find(kosulop);
                string sol = kosul.substr(0,konum);
                string sag = kosul.substr(konum+2);
                for(int i = 0;i<vec_of_doubles.size();i++){
                    if(vec_of_doubles[i].name == sol){
                        soldeger = vec_of_doubles[i].value;
                        solbulundu = true;
                    }
                    if(vec_of_doubles[i].name == sag){
                        sagdeger = vec_of_doubles[i].value;
                        sagbulundu = true;
                    }
                }
                if (!solbulundu){
                    //soldeger = stod(sol);
                    stringstream koray(sol);
                    koray >> soldeger;
                }
                if(!sagbulundu){
                    //sagdeger = stod(sag);
                    stringstream koray(sag);
                    koray >> sagdeger;
                }
                if(check(sol)){
                    soldeger=calculatoroparator(sol);
                }
                if(check(sag)){
                    sagdeger=calculatoroparator(sag);
                }
                if(soldeger != sagdeger){
                    for(int i = 0;i<vec_of_doubles.size();i++){
                        if(vec_of_doubles[i].name == dogruysa){
                            double kosuldeger = vec_of_doubles[i].value;
                            return kosuldeger;
                        }
                    }
                }
                else{
                    for(int i = 0;i<vec_of_doubles.size();i++){
                        if(vec_of_doubles[i].name == yanlissa){
                            double kosuldeger = vec_of_doubles[i].value;
                            return kosuldeger;
                        }
                    }
                }
            }
        }
    }
    else if(rightside.find("(") != std::string::npos){
        KeyValue <double> A;
        int parantezopa;
        int konumAcma=rightside.find("(");
        int konumKapatma=rightside.find(")");
        string parantezici = rightside.substr(konumAcma+1,konumKapatma-(konumAcma+1));
        string nobrackets = removebrackets(rightside);
        double val = calculatoroparator(parantezici);
        parantezici.insert(0,"&");
        parantezici.insert(parantezici.size(),"&");
        if(parantezici.find("+") != std::string::npos){parantezopa=parantezici.find("+"); parantezici.erase(parantezopa,1);}
        else if(parantezici.find("-") != std::string::npos){parantezopa=parantezici.find("-"); parantezici.erase(parantezopa,1);}
        else if(parantezici.find("/") != std::string::npos){parantezopa=parantezici.find("/"); parantezici.erase(parantezopa,1);}
        else if(parantezici.find("*") != std::string::npos){parantezopa=parantezici.find("*"); parantezici.erase(parantezopa,1);}
        nobrackets.erase(konumAcma,konumKapatma-(konumAcma+1));
        nobrackets.insert(konumAcma,parantezici);
        A.name = parantezici;
        A.value = val;
        vec_of_doubles.push_back(A);
        if(check(nobrackets)){
            double sonuc = calculatoroparator(nobrackets);
            return sonuc;
        }
        return val;
        }
    else if(rightside.find("+")!= std::string::npos){
        konum=rightside.find("+");
        string sol = rightside.substr(0,konum);
        string sag = rightside.substr(konum+1);
        for(int i = 0;i<vec_of_doubles.size();i++){
            if(vec_of_doubles[i].name == sol){
                soldeger = vec_of_doubles[i].value;
                solbulundu = true;
            }
            if(vec_of_doubles[i].name == sag){
                sagdeger = vec_of_doubles[i].value;
                sagbulundu = true;
            }
        }
        if (!solbulundu){
            //soldeger = stod(sol);
            stringstream koray(sol);
            koray >> soldeger;
        }
        if(!sagbulundu){
            //sagdeger = stod(sag);
            stringstream koray(sag);
            koray >> sagdeger;
        }
        if(check(sol)){
            soldeger=calculatoroparator(sol);
        }
        if(check(sag)){
            sagdeger=calculatoroparator(sag);
        }

        return soldeger + sagdeger;
    }
    else if(rightside.find("-")!= std::string::npos){
        konum=rightside.find("-");
        string sol = rightside.substr(0,konum);
        string sag = rightside.substr(konum+1);
        for(int i = 0;i<vec_of_doubles.size();i++){
            if(vec_of_doubles[i].name == sol){
                soldeger = vec_of_doubles[i].value;
                solbulundu = true;
            }
            if(vec_of_doubles[i].name == sag){
                sagdeger = vec_of_doubles[i].value;
                sagbulundu = true;
            }
        }
        if (!solbulundu){
            //soldeger = stod(sol);
            stringstream koray(sol);
            koray >> soldeger;
        }
        if(!sagbulundu){
            //sagdeger = stod(sag);
            stringstream koray(sag);
            koray >> sagdeger;
        }
        if(check(sol)){
            soldeger=calculatoroparator(sol);
        }
        if(check(sag)){
            sagdeger=calculatoroparator(sag);
        }
        return soldeger - sagdeger;
    }

    else if(rightside.find("*")!= std::string::npos){
        konum=rightside.find("*");
        string sol = rightside.substr(0,konum);
        string sag = rightside.substr(konum+1);
        for(int i = 0;i<vec_of_doubles.size();i++){
            if(vec_of_doubles[i].name == sol){
                soldeger = vec_of_doubles[i].value;
                solbulundu = true;
            }
            if(vec_of_doubles[i].name == sag){
                sagdeger = vec_of_doubles[i].value;
                sagbulundu = true;
            }
        }
         if (!solbulundu){
            //soldeger = stod(sol);
            stringstream koray(sol);
            koray >> soldeger;
        }
        if(!sagbulundu){
            //sagdeger = stod(sag);
            stringstream koray(sag);
            koray >> sagdeger;
        }
         if(check(sol)){
            soldeger=calculatoroparator(sol);
        }
        if(check(sag)){
            sagdeger=calculatoroparator(sag);
        }
        return soldeger * sagdeger;
    }
    else if(rightside.find("/")!= std::string::npos){
        konum=rightside.find("/");
        string sol = rightside.substr(0,konum);
        string sag = rightside.substr(konum+1);

        for(int i = 0;i<vec_of_doubles.size();i++){
            if(vec_of_doubles[i].name == sol){
                soldeger = vec_of_doubles[i].value;
                solbulundu = true;
            }
            if(vec_of_doubles[i].name == sag){
                sagdeger = vec_of_doubles[i].value;
                sagbulundu = true;
            }
        }
        if (!solbulundu){
            //soldeger = stod(sol);
            stringstream koray(sol);
            koray >> soldeger;
        }
        if(!sagbulundu){
            //sagdeger = stod(sag);
            stringstream koray(sag);
            koray >> sagdeger;
        }
        if(check(sol)){
            soldeger=calculatoroparator(sol);
        }
        if(check(sag)){
            sagdeger=calculatoroparator(sag);
        }
        return soldeger / sagdeger;
    }
    else{
        stringstream koray(rightside);
        koray >> soldeger;
        return soldeger;
    }
}
double istenen_yazdirma(string line){
    double istenendeger;
        for(int i=0;i<vec_of_doubles.size();i++){
            if(vec_of_doubles[i].name==line.substr(3)){
                    istenendeger = vec_of_doubles[i].value;
                }
        }
    return istenendeger;
}
int main()
{
    KeyValue <double> A;
    string leftside;
    string rightside;
    string line;
    ifstream okumadosyasi("okuma.inp");
    while(getline(okumadosyasi,line)){
        line = removeSpaces(line);
        if(line.substr(0,3)=="OUT"){
            ofstream yazmadosyasi("yazma.out");
            yazmadosyasi << istenen_yazdirma(line) <<endl;
            yazmadosyasi.close();
            break;
        }
        int konum=line.find("=",0);
        if(line.find("LOOP")!= string::npos){
            double sonuc;
            int time;
            leftside = line.substr (4,konum-4);
            A.name=leftside;
            rightside = line.substr(konum+1);
            int konumTIMES = rightside.find("TIMES")+4;
            string timestr = rightside.substr(konumTIMES+1);
            string islemstr = rightside.substr(0,konumTIMES-4);
            stringstream koray(timestr);
            koray >> time;
            for(int i = 0;i<time;i++){
                A.value=calculatoroparator(islemstr);
                vec_of_doubles.push_back(A);
            }
        }
        else{
            leftside = line.substr(0, konum);
            A.name=leftside;
            rightside = line.substr(konum+1);
            A.value=calculatoroparator(rightside);
            vec_of_doubles.push_back(A);
        }

    }
    okumadosyasi.close();
    return 0;
}
