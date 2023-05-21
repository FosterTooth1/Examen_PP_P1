import math
import random

# Flores Lara Alberto; Luna Zamora Juan Antonio; Saucillo González Jesse Obed 	3BV2

class Punto3D:
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def distancia(self, otro_punto):
        dx = self.x - otro_punto.x
        dy = self.y - otro_punto.y
        dz = self.z - otro_punto.z
        return math.sqrt(dx**2 + dy**2 + dz**2)

def encontrar_par_mas_cercano(puntos):
    par_cercano = (None, None)
    distancia_minima = float('inf')

    for i in range(len(puntos)):
        for j in range(i + 1, len(puntos)):
            distancia = puntos[i].distancia(puntos[j])
            if distancia < distancia_minima:
                distancia_minima = distancia
                par_cercano = (puntos[i], puntos[j])

    return par_cercano

def generar_puntos_aleatorios(n):
    puntos = []
    for _ in range(n):
        x = round(random.uniform(-10, 10), 3)
        y = round(random.uniform(-10, 10), 3)
        z = round(random.uniform(-10, 10), 3)
        punto = Punto3D(x, y, z)
        puntos.append(punto)
        print("Punto generado: P({}, {}, {})".format(punto.x, punto.y, punto.z))
    return puntos

def ingresar_puntos_manualmente(n):
    puntos = []
    for i in range(n):
        print("Punto #{}".format(i + 1))
        x = float(input("x: "))
        y = float(input("y: "))
        z = float(input("z: "))
        punto = Punto3D(x, y, z)
        puntos.append(punto)
        print("Punto ingresado: P({}, {}, {})".format(punto.x, punto.y, punto.z))
    return puntos

print("¿Cómo desea generar los puntos?")
print("1. Aleatoriamente")
print("2. Manualmente")
print("3. Desde un archivo")
opcion = int(input("Opción: "))
while opcion != 1 and opcion != 2 and opcion != 3:
    print("Opción inválida.")
    opcion = int(input("Opción: "))
print()

if opcion == 1:
    puntos = generar_puntos_aleatorios(20)
elif opcion == 2:
    puntos = ingresar_puntos_manualmente(20)
elif opcion == 3:
    print("Si el archivo esta en la misma carpeta que este programa, solo ingrese el nombre del archivo.")
    print("Si el archivo esta en otra carpeta, ingrese la ruta completa del archivo.")
    archivo = input("Ingrese el nombre del archivo de puntos: ")
    puntos = []
    try:
        print("Leyendo puntos desde el archivo {}...".format(archivo))
        with open(archivo, 'r') as file:
            for linea in file:
                valores = linea.strip().strip('P()').split(',')
                x = round(float(valores[0]), 3)
                y = round(float(valores[1]), 3)
                z = round(float(valores[2]), 3)
                punto = Punto3D(x, y, z)
                puntos.append(punto)
                print("Punto leído: P({}, {}, {})".format(punto.x, punto.y, punto.z))
    except FileNotFoundError:
        print("Archivo no encontrado. Se generarán puntos aleatorios en su lugar.")
        puntos = generar_puntos_aleatorios(20)

# Encontrar el par más cercano
par_cercano = encontrar_par_mas_cercano(puntos)

# Imprimir el resultado
if par_cercano[0] is not None and par_cercano[1] is not None:
    print("El par más cercano de puntos en 3D es:")
    print("P1: P({}, {}, {})".format(par_cercano[0].x, par_cercano[0].y, par_cercano[0].z))
    print("P2: P({}, {}, {})".format(par_cercano[1].x, par_cercano[1].y, par_cercano[1].z))
    print("Distancia:", par_cercano[0].distancia(par_cercano[1]))
else:
    print("No se encontró un par de puntos cercanos.")
