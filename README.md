# 🚃Sincronização de threads em C


Esse repositório contém uma implementação simples e básica de como funciona a manutenção e sincronização de múltiplas threads dentro da CPU. Implementado através de bibliotecas como pthreads, o código se utiliza de um runner pré escrio e com funções adicionais que simulam um ambiente de embarque ferroviário, em que cada vagão consiste de uma thread na CPU e que deve acompanhar a chegada de vagões, subida de passageiros (threads dormindo) e saída de vagões (threads executadas)


## 📖Conteúdo do repositório

Dentro da pasta src existem três arquivos:
- sync_car.c: Arquivo escrito nessa implementação, contém as funções requisitadas responsáveis por gerenciar as seções críticas, entrada e saída das threads nas queue.

- sync_car-runner.c: Arquivo pré escrito responsável por executar as funções em uma situação exemplo (dado pelo professor)

- sync_car.h: Arquivo header responsável por definir as funções e a estrutura da struct

Fora da pasta src também há o arquivo Makefile responsável pela automação da compilação e execução do código


## ✍️Como reproduzir 

Com o repositório clonado e dentro da pasta src, para compilar:

```
make clean
make
```

Para executar:

```
./sync_car
```

O código deve executar o runner.c, que realizará a sincronização de uma série de vagões (threads). Caso o resultado esteja dentro do esperado, aparecerá a mensagem "Looks good!" ao final

Esse código foi escrito por Telmo Melo (telmo-wq) em um sistema Fedora Linux