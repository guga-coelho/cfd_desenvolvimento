import pandas as pd
from pandas import ExcelWriter
from pandas import ExcelFile
from openpyxl import load_workbook
import numpy as np
import matplotlib.pyplot as plt
import os as op

def chamar_back_end():
    print("ARQUIVO NÃO FOI LIDO, INFORME: ")
    nome_in = input("Informe o nome do arquivo que sera lido: ")
    qtd_coord = input("Informe a quantidade de coordenadas que o arquivo possui: ")
    #itmin = input("Informe o periodo a ser ignorado no arquivo: ")
    qtd_linhas = input("Informe a quantidade de linhas: ")
    itmin = "0"
    time_escolhido = input("Informe o tempo escolhido entre: "+ str((float(itmin)/1000)) +" e " + str((float(qtd_linhas)/1000)) +" \nExemplo: 4.326 ou 4: ")
    
    #op.system("rotina_pos_processo_1.exe "+nome_in+" "+qtd_coord+" "+itmin+" "+qtd_linhas+" "+time_escolhido)

#pegando os valores e gerando adequadamente
def gerar_correlacao():
    with open("arquivo_saida_coord","r") as f:
        aux2 = f.readline()

    aux = aux2.split('/')
    aux.remove(aux[-1])

    pontos_x = []
    pontos_y = []

    y_ok = 0

    for i in aux:
        if i == 'x':
            y_ok = 1
        else:
            if y_ok == 1:
                pontos_x.append(float(i)) #adicionar valores em x
            else:
                pontos_y.append(float(i)) #adicionar valores em y

    f.close()

    nome_out = input("Informe o nome de saída: ")
    tipo_texto = ".xlsx"
    nome_out_completo = nome_out + tipo_texto

    writer = pd.ExcelWriter(nome_out_completo, engine='openpyxl')
    wb  = writer.book
    df = pd.DataFrame({'y^2': pontos_y,
                    'Ux': pontos_x})

    df.to_excel(writer, index=False)
    wb.save(nome_out_completo)

    correl = pd.read_excel(nome_out_completo)

    resultado = correl.corr(method = 'pearson')

    print(resultado)

#chamar_back_end()
gerar_correlacao()
