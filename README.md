# gametools
C++ gametools using SFML

## **Using Git**

### **Clonar el Proyecto**
```git
git clone  https://github.com/horaciodrs/gametools.git
git config --global user.name "Horacio Daniel Ros"
git config --global user.email "horaciodrs@gmail.com"
```
 
### **Subir Cambios**
```git
git add .
git commit -m "Mensaje...."
git push -u origin master
```

## **Compilar**
	
- En Linux
```sh
sudo apt install build-essential libsfml-dev
g++ lib/*.cpp *.cpp -o game  -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
```
- En Windows
 ```sh
 g++ -LC:\SFML-2.5.1\lib lib/*.cpp *.cpp -o game  -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
 ```