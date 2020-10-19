#include <iostream>
using namespace std;
float babilon(float x){
 float t1=0,t2=1;
 if(t1!=t2){
 t1=t2;
t2=(t1+x/t1)/2; }
if(t1!=t2){
 t1=t2;
t2=(t1+x/t1)/2; }
if(t1!=t2){
 t1=t2;
t2=(t1+x/t1)/2; }
if(t1!=t2){
 t1=t2;
t2=(t1+x/t1)/2; }
if(t1!=t2){
 t1=t2;
t2=(t1+x/t1)/2; }
if(t1!=t2){
 t1=t2;
t2=(t1+x/t1)/2; }
return t2;}
int main(){
float liczba;cin >> liczba;
cout << babilon(liczba) << endl;
return 0;}