#include <vector>
#include "algobot.h"

using namespace std;

// Ejercicio 1
int apariciones(vector<int> v, int n){
    int sum=0;
    for(int i=0;i<v.size();i++){
        if(n==v[i]){
            sum=sum+1;
        }
    }
    return sum;
}

vector<int> quitar_repetidos(vector<int> s) {
    //vector<int> res;
    //vector<int> s1 = s;
    //if(s.size()==0) {
        //res = res;
    //}else{
        //res.push_back(s[0]);
        //for (int i = 0; i < s.size(); i++) {
                //if(apariciones(res,s[i])==0) {
                    //res.push_back(s[i]);
                //}
            //}
        //}

    //return res;
    vector<int> respuesta;
    for(int i = 0; i < s.size();i++){
        if(apariciones(respuesta, s[i])==0){
            respuesta.push_back(s[i]);
        }
    }
    return respuesta;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    //set<int> set_s;
    //vector<int> res;
    //if(s.size()==0){
        //res=s;
    //}else {
        //set_s.insert(s[0]);
        //res.push_back(s[0]);
        //for(int i = 0; i < s.size(); i++) {
            //if (set_s.count(s[i])==0){
                //set_s.insert(s[i]);
                //res.push_back(s[i]);
            //}
        //}
    //}
    //return res;
    set<int> respuesta;
    for(int j = 0; j < s.size();j++){
        if(respuesta.count(s[j])==0){
            respuesta.insert(s[j]);
        }
    }
    vector<int> copiar(respuesta.begin(), respuesta.end());
    return copiar;


}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    //set<int> set_a;
    //set<int> set_b;
    //vector<int> a2 = quitar_repetidos_v2(a);
    //vector<int> b2 = quitar_repetidos_v2(b);
    //bool res=false;
    //if(a2.size()==b2.size()) {
        //if (a.size() == 0 && b.size() == 0) {
            //res = true;
        //} else {
            //for (int i = 0; i < a2.size(); i++) {
                //set_a.insert(a2[i]);
                //set_b.insert(b2[i]);
                //if (set_a.count(a2[i]) == set_b.count(a2[i])) {
                    //res = res || true;
                //} else {
                    //res = false;
                //}
            //}
        //}
    //}else{
        //res=false;
    //}
    //return res;
    bool respuesta = true;
    for(int i = 0; i<a.size(); i++){
        if(1<=apariciones(b, a[i])){
            respuesta = respuesta & true;
        }else{
            respuesta = false;
        }
    }
    return respuesta;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    set<int> set_a;
    for(int i =0;i<a.size();i++){
        set_a.insert(a[i]);
    }
    bool respuesta = true;
    for(int j = 0; j<b.size();j++){
        if(set_a.count(b[j])>=1){
            respuesta = respuesta & true;
        }else{
            respuesta = false;
        }
    }
    return respuesta;
}
//Preguntar el 4 porque no tienen los mismos elementos

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    //map<int, int> res;
    //vector<int> s2= quitar_repetidos_v2(s);
    //for(int i = 0;i<s2.size();i++){
        //res[s2[i]]=apariciones(s, s2[i]);
        //}
    //return res;
    map<int,int> respuesta;
    vector<int> claves = quitar_repetidos(s);
    for(int i = 0; i<claves.size();i++){
        respuesta[claves[i]] = apariciones(s,claves[i]);
    }
    return respuesta;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    vector<int> res;
    for(int i=0; i<s.size();i++){
        if(apariciones(s,s[i])==1){
            res.push_back(s[i]);
        }
    }
    return res;


}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    vector<int> vector_a(a.begin(),a.end());
    set<int> respuesta;
    for(int i = 0; i<vector_a.size();i++){
        if(b.count(vector_a[i])==1){
            respuesta.insert(vector_a[i]);
        }
    }
    return respuesta;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    return map<int, set<int>>();
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    return vector<char>();
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    return true;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
  return map<set<LU>, Mail>();
}
