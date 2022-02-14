import numpy as np
import matplotlib.pyplot as plt

pontos_y = []
pontos_x = []
a = 0

with open("geracao_grafico_x","r") as f:
    aux = f.readline()

aux_2 = aux.split("/")
aux_2.remove(aux_2[0])
print(aux_2)


y_ok = 0

for i in aux_2:
    if i == 'y':
        y_ok = 1

    if y_ok != 1:
        pontos_x.append(float(i))
    else:
        if i != 'y':
            pontos_y.append(float(i))

f.close()

print(pontos_x)
print(pontos_y)

plt.plot(pontos_x, pontos_y)
plt.title('Gráfico de velocidades médias:')
plt.show()