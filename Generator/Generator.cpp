#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h> 
#include <stdio.h>
using namespace std;
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>


string concatenate(float x, float y, float z) {

    return to_string(x) + " " + to_string(y) + " " + to_string(z);

}


void drawPlane(float length, int divisions, string name) {

    float x = length;
    float z = float(length);
    float pointX = (float)length / divisions;
    float pointZ = (float)length / divisions;

    x = x / 2;
    z = z / 2;

    fstream(file);
    file.open("/Users/Asus/Desktop/trabCG/3D/" + name, fstream::out);
    
    if (file.is_open()) {
        int vertices = 2 * divisions * divisions * 3;
        file << to_string(vertices) << endl;

        for (int i = 0; i < divisions; i++) {
            for (int j = 0; j < divisions; j++) {

                //plano
                file << concatenate(-x + (i * pointX), 0.0f, -z + (j * pointZ)) << endl;
                file << concatenate(-x + (i * pointX), 0.0f, -z + (j * pointZ) + pointZ) << endl;
                file << concatenate(-x + (i * pointX) + pointX, 0.0f, -z + (j * pointZ) + pointZ) << endl;

                file << concatenate(-x + (i * pointX), 0.0f, -z + (j * pointZ)) << endl;
                file << concatenate(-x + (i * pointX) + pointX, 0.0f, -z + (j * pointZ) + pointZ) << endl;
                file << concatenate(-x + (i * pointX) + pointX, 0.0f, -z + (j * pointZ)) << endl;


            }
        }
        file.close();

    }
    else { cout << "Nao abriu o ficheiro." << endl; }
}

void drawBox(float size, int divisions, string name) {
    float x = size;
    float y = size;
    float z = size;

    float pointX = size / (float)divisions;
    float pointY = size / (float)divisions;
    float pointZ = size / (float)divisions;

    x = x / 2;
    z = z / 2;
    float mid = y / 2;

    fstream(file);
    file.open("/Users/Asus/Desktop/trabCG/3D/" + name, fstream::out);

    if (file.is_open()) {
        int vertices = 6 * 2 * divisions * divisions * 3;
        file << to_string(vertices) << endl;

        for (int i = 0; i < divisions; i++) {
            for (int j = 0; j < divisions; j++) {

                //plano cima
                file << concatenate(-x + (i * pointX), y - mid, -z + (j * pointZ)) << endl;
                file << concatenate(-x + (i * pointX), y - mid, -z + (j * pointZ) + pointZ) << endl;
                file << concatenate(-x + (i * pointX) + pointX, y - mid, -z + (j * pointZ) + pointZ) << endl;

                file << concatenate(-x + (i * pointX), y - mid, -z + (j * pointZ)) << endl;
                file << concatenate(-x + (i * pointX) + pointX, y - mid, -z + (j * pointZ) + pointZ) << endl;
                file << concatenate(-x + (i * pointX) + pointX, y - mid, -z + (j * pointZ)) << endl;

                //plano baixo
                file << concatenate(-x + (i * pointX), 0.0f - mid, z - (j * pointZ)) << endl;
                file << concatenate(-x + (i * pointX), 0.0f - mid, z - (j * pointZ) - pointZ) << endl;
                file << concatenate(-x + (i * pointX) + pointX, 0.0f - mid, z - (j * pointZ) - pointZ) << endl;

                file << concatenate(-x + (i * pointX), 0.0f - mid, z - (j * pointZ)) << endl;
                file << concatenate(-x + (i * pointX) + pointX, 0.0f - mid, z - (j * pointZ) - pointZ) << endl;
                file << concatenate(-x + (i * pointX) + pointX, 0.0f - mid, z - (j * pointZ)) << endl;

                //plano frente
                file << concatenate(-x + (i * pointX), y - (j * pointY) - mid, z) << endl;
                file << concatenate(-x + (i * pointX), y - (j * pointY) - pointY - mid, z) << endl;
                file << concatenate(-x + (i * pointX) + pointX, y - (j * pointY) - pointY - mid, z) << endl;

                file << concatenate(-x + (i * pointX), y - (j * pointY) - mid, z) << endl;
                file << concatenate(-x + (i * pointX) + pointX, y - (j * pointY) - pointY - mid, z) << endl;
                file << concatenate(-x + (i * pointX) + pointX, y - (j * pointY) - mid, z) << endl;

                //plano tras
                file << concatenate(-x + (i * pointX) + pointX, j * pointY - mid, -z) << endl;
                file << concatenate(-x + (i * pointX), j * pointY - mid, -z) << endl;
                file << concatenate(-x + (i * pointX) + pointX, (j * pointY) + pointY - mid, -z) << endl;

                file << concatenate(-x + (i * pointX), j * pointY - mid, -z) << endl;
                file << concatenate(-x + (i * pointX), (j * pointY) + pointY - mid, -z) << endl;
                file << concatenate(-x + (i * pointX) + pointX, j * pointY + pointY - mid, -z) << endl;

                //plano esquerdo
                file << concatenate(-x, y - (i * pointY) - mid, -z + (j * pointZ)) << endl;
                file << concatenate(-x, y - (i * pointY) - pointY - mid, -z + (j * pointZ)) << endl;
                file << concatenate(-x, y - (i * pointY) - pointY - mid, -z + (j * pointZ) + pointZ) << endl;

                file << concatenate(-x, y - (i * pointY) - mid, -z + (j * pointZ)) << endl;
                file << concatenate(-x, y - (i * pointY) - pointY - mid, -z + (j * pointZ) + pointZ) << endl;
                file << concatenate(-x, y - (i * pointY) - mid, -z + (j * pointZ) + pointZ) << endl;

                //plano direito
                file << concatenate(x, y - (i * pointY) - mid, z - (j * pointZ)) << endl;
                file << concatenate(x, y - (i * pointY) - pointY - mid, z - (j * pointZ)) << endl;
                file << concatenate(x, y - (i * pointY) - pointY - mid, z - (j * pointZ) - pointZ) << endl;

                file << concatenate(x, y - (i * pointY) - mid, z - (j * pointZ)) << endl;
                file << concatenate(x, y - (i * pointY) - pointY - mid, z - (j * pointZ) - pointZ) << endl;
                file << concatenate(x, y - (i * pointY) - mid, z - (j * pointZ) - pointZ) << endl;

            }
        }

        file.close();
    }
    else { cout << "Nao abriu o ficheiro." << endl; }
}

void drawCone(float radius, float height, int slices1, int stacks1, string name) {
    float slices = (float)slices1;
    float stacks = (float)stacks1;
    fstream file;
    file.open("/Users/Asus/Desktop/trabCG/3D/" + name, fstream::out);

    float raio = radius / stacks;
    float altura = height / stacks;
    int i, j;

    int vertices = 3 * slices1 + ((6 * stacks1) * slices1);
    file << to_string(vertices) << endl; 

    if (file.is_open()) {

        //fazer a circunfer�ncia da base
        for (i = 0; i < slices; i++) {
            float alfa = (i * 2 * M_PI) / slices;
            float nextalfa = ((i + 1) * 2 * M_PI) / slices;

            // base
            file << "0 0 0\n";
            file << radius * sin(nextalfa) << " 0 " << radius * cos(nextalfa) << "\n";
            file << radius * sin(alfa) << " 0 " << radius * cos(alfa) << "\n";


        }
        // Fazer as laterais
        float rAtual = radius;
        float rProx = radius - raio;
        float altAtual = 0;
        float altProx = altura;


        for (i = 0; i < slices; i++) {


            for (j = 0; j < stacks; j++) {
                float alfa = (i * 2 * M_PI) / slices;
                float nextalfa = ((i + 1) * 2 * M_PI) / slices;
                file << concatenate(rAtual * sin(nextalfa), altAtual, rAtual * cos(nextalfa)) << endl;
                file << concatenate(rProx * sin(nextalfa), altProx, rProx * cos(nextalfa)) << endl;
                file << concatenate(rAtual * sin(alfa), altAtual, rAtual * cos(alfa)) << endl;

                file << concatenate(rProx * sin(nextalfa), altProx, rProx * cos(nextalfa)) << endl;
                file << concatenate(rProx * sin(alfa), altProx, rProx * cos(alfa)) << endl;
                file << concatenate(rAtual * sin(alfa), altAtual, rAtual * cos(alfa)) << endl;


                rAtual -= raio;
                rProx -= raio;
                altAtual += altura;
                altProx += altura;
            }

            rAtual = radius;
            rProx = radius - raio;
            altAtual = 0;
            altProx = altura;
        }

    }
    else { cout << "Nao abriu o ficheiro." << endl; }
}




void dawSphere(float radius, int slices, int stacks, string name) {

    fstream(file);
    file.open("/Users/Asus/Desktop/trabCG/3D/" + name, fstream::out);

    int vertices = 6 * slices * stacks;
    file << to_string(vertices) << endl;

    if (file.is_open()) {

        // slices - fatias
        float alfa = 2 * M_PI / (float)slices;
        float nextalfa = alfa + 2 * M_PI / (float)slices;

        // stack  - camadas
        float beta = -M_PI / (float)stacks;
        float nextbeta = beta + M_PI / (float)stacks;

        for (int i = 0; i < slices; i++) {
            beta = -M_PI / 2;
            nextbeta = beta + M_PI / (float)stacks;

            alfa = i * 2 * M_PI / (float)slices;
            nextalfa = alfa + 2 * M_PI / (float)slices;

            for (int j = 0; j < stacks; j++) {

                file << concatenate(radius * cos(beta) * sin(alfa), radius * sin(beta), radius * cos(beta) * cos(alfa)) << endl;
                file << concatenate(radius * cos(beta) * sin(nextalfa), radius * sin(beta), radius * cos(beta) * cos(nextalfa)) << endl;
                file << concatenate(radius * cos(nextbeta) * sin(alfa), radius * sin(nextbeta), radius * cos(nextbeta) * cos(alfa)) << endl;
                file << concatenate(radius * cos(beta) * sin(nextalfa), radius * sin(beta), radius * cos(beta) * cos(nextalfa)) << endl;
                file << concatenate(radius * cos(nextbeta) * sin(nextalfa), radius * sin(nextbeta), radius * cos(nextbeta) * cos(nextalfa)) << endl;
                file << concatenate(radius * cos(nextbeta) * sin(alfa), radius * sin(nextbeta), radius * cos(nextbeta) * cos(alfa)) << endl;

                beta += M_PI / stacks;
                nextbeta = beta + M_PI / stacks;
            }
            beta += M_PI / stacks;
            nextbeta = beta + M_PI / stacks;
        }
        file.close();

    }
    else { cout << "Nao abriu o ficheiro." << endl; }
}



void showSintaxError() {
    cout << "Sintax error:\n";
    cout << "  Usage: ./generator [Shape] [Args] [Output File]\n";
    cout << "  Shapes available: \n";
    cout << "  Plane: [length] [divisions]\n";
    cout << "  Box: [size] [divisions]\n";
    cout << "  Cone: [radious] [heigth] [slices] [stacks]\n";
    cout << "  Sphere: [radious] [slices] [stacks]\n";
    exit(-1);
}

//Esta funcao ira ignorar uppercase e lowercase
bool iequals(const string& a, const string& b) {
    return std::equal(a.begin(), a.end(),
        b.begin(), b.end(),
        [](char a, char b) {
            return tolower(a) == tolower(b);
        });
}

int main(int argc, char** argv) {
    printf("argc: %d\n", argc);
    if (argc == 1) showSintaxError();

    if (iequals(argv[1], "Plane")) {
        if (argc != 5) showSintaxError();
        cout << "Plane" << endl;
        cout << "Length: " << atof(argv[2]) << endl;
        cout << "Divisions: " << atoi(argv[3]) << endl;
        cout << "File:" << argv[4] << endl;
        drawPlane(atof(argv[2]), atoi(argv[3]), argv[4]);
    }
    else if (iequals(argv[1], "Box")) {
        if (argc != 5) showSintaxError();
        cout << "Box" << endl;
        cout << "Size: " << atof(argv[2]) << endl;
        cout << "Divisions: " << atoi(argv[3]) << endl;
        cout << "File: " << argv[4] << endl;
        drawBox(atof(argv[2]), atoi(argv[3]), argv[4]);
    }
    else if (iequals(argv[1], "Cone")) {
        if (argc != 7) showSintaxError();
        cout << "Cone" << endl;
        cout << "Radius: " << atof(argv[2]) << endl;
        cout << "Height: " << atof(argv[3]) << endl;
        cout << "Slices: " << atoi(argv[4]) << endl;
        cout << "Stacks: " << atoi(argv[5]) << endl;
        cout << "File: " << argv[6] << endl;
        drawCone(atof(argv[2]), atof(argv[3]), atoi(argv[4]), atoi(argv[5]), argv[6]);
    }
    else if (iequals(argv[1], "Sphere")) {
        if (argc != 6) showSintaxError();
        cout << "Sphere" << endl;
        cout << "Radius: " << atof(argv[2]) << endl;
        cout << "Slices: " << atoi(argv[3]) << endl;
        cout << "Stacks: " << atoi(argv[4]) << endl;
        cout << "File: " << argv[5] << endl;
        dawSphere(atof(argv[2]), atoi(argv[3]), atoi(argv[4]), argv[5]);
    }
    else showSintaxError();

    return 1;
}