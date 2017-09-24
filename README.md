#Acionamento por Infravermelho com Dispositivo Atuador Genérico

***Dispositivo residencial restinado a fabricação no parque industriário
brasileiro.***

Melisse Pontes Cabral

Universidade Federal do Ceará

Sobral, Ceará

melissecabral@gmail.com

Julio C. F. Lima,

Universidade Federal do Ceará

Sobral, Ceará

julio\_flima@hotmail.com;

<b>*Abstract*—This report proposes to present the development of a
residential automation destined to be manufactured in the Brazilian
industry. They were used to carry out the project by developing free
software like Arduino IDE. During the report, several development
environments will be presented, targeting not only the hardware, but
also the software and the results of the final object. 

*Key-words: home automation; Arduino; IRremote; TSOP.*</b>

Descrição e Objetivos
=====================

A proposta do projeto é trazer um dispositivo de automação de simples
instalação e uso a um baixo custo, para que fosse possível sua inserção
no mercado brasileiro. Isso foi fator determinante para a escolha de
componentes utilizados na concepção do protótipo.

Os sensores infravermelhos para a recepção de dados proporcionam uma
série de vantagens quando comparado a outros tipos de comunicação sem
fio, como baixo custo, simplicidade de implementação e pela sua baixa
vulnerabilidade a ruídos externos, desse modo é um tipo de comunicação
robusta (HAYKIN; VEEN, 2003). O controle remoto é um objeto comum a
vários dispositivos eletrônicos presentes no cotidiano, em sua maioria é
comum encontrar teclas que não possuem nenhuma funcionalidade, com o
dispositivo é possível utilizar essas teclas. Isso é possível devido aos
botões programáveis presentes no dispositivo que ao ser pressionado
espera receber um novo valor passado pelo controle e o cadastra para
acionamento, o que torna possível a troca de controles ou até mesmo uma
melhor configurações de teclas.

O protótipo atendeu aos objetivos precitados como a possibilidade de ser
adquirido por pessoas de baixo poder de compra e a difusão das
tecnologias aplicadas no protótipo, dado ao baixo custo de
desenvolvimento empregado.

Metodologia
===========

Durante projeto foram utilizados, módulo de sensor infravermelho TSOP
1738 \[7\] utilizado para fazer a comunicação entre o Arduino \[10\] e o
controle remoto, Arduino Pro Mini com o microcontrolador ATmega168,
usado para receber dados do TSOP e controlar os acionamentos que são
possíveis utilizando relés, resistores, transistores e diodos. Também
foram utilizados dois botões para sinalizar a gravação do botão desejado
e um controle remoto genérico para ligar e desligar os equipamentos
conectados ao dispositivo desenvolvido.

Aquisição de dados
------------------

O microcontrolador ATmega168 possui uma arquitetura baseada em RISC,
garante um bom desempenho a baixo consumo de energia, sendo limitado
apenas pela memória em relação ao bastante difundido ao ATmega328.
Entretanto atende bem as necessidades do protótipo pois não há uma
grande necessidade de alocação de memória para o funcionamento do
dispositivo. Há a possibilidade de usar portas analógicas ou digitais,
porém nesse projeto foram utilizadas exclusivamente as portas digitais.
A aquisição de dados é feita pela comunicação em infravermelho.

<b>1. Arduino:</b> O dispositivo utilizado foi o Arduino Pro Mini por se tratar de um dispositivo pensado pra ser semi-permanente, dado que trata de um plataforma de desenvolvimento provisória destinada a protótipos. Possue quatorze portas digitais e seis portas as analógicas que podem ser utilizadas para recepção e envio de dados. O modelo o ATmega168 possui tensão de alimentação de 5V, com uma memória flash de apenas 16 KB, o que é suficiente para a programação do dispositivo. Esse modelo de microcontrolador possui um clock de 16 MHz que atendeu bem as necessidades do protótipo. 

<b>2. Digital:</b> As portas digitais possuem um funcionamento padrão no qual há apenas dois estados o HIGH e o LOW e funciona em níveis lógicos. O estado LOW compreende ao valor de 0V, enquanto o HIGH compreende valores recebidos superiores a 3V. Essas portas podem ser utilizadas tanto como entrada de dados como saída. No projeto for utilizada tanto portas digitais de entrada como de saida. Foram dedicadas duas portas ao acionamento dos relés, que por sua vez aciona o equipamento. Entretanto para a utilização de sensores modernos com leitura de dados diferentes de valores lógicos são usadas bibliotecas específicas para leitura e transmissão de dados. A exemplo desse tipo de sensor temos o TSOP que opera recebendo hexadecimais, por meio de uma porta digital os envia ao microcontrolador que utiliza a biblioteca “IRremote” \[8\] para interpretar as palavras recebidas.

### 

Protocolo IR
------------

A tecnologia de infravermelho é um protocolo de transmissão sem fio de
dados usados para controlar e operar diversos dispositivos, a
transferência de dados de infravermelho é implementada de acordo com os
protocolos e padrões da IrDA (Infrared Data Association). Esses padrões
são projetados para aceitar componentes de baixo custo e reduzir a
demanda de energia, e para ativar conexões simplesmente apontando
dispositivos de infravermelho um para o outro (BARKER, et al, 2002).

Entre os vários protocolos de comunicação IR existentes, todos possuem
objetivos em comum como: velocidade do canal completo, segurança, baixo
custo, baixa manutenção, circuitos de fácil implementação, mas
diferenciam-se no modo de comunicação e na transmissão dos dados tendo
variações no número de instruções, tamanho da palavra de bits
transmitida, no consumo de energia, compatibilidade com dispositivos
eletrônicos, faixa de frequência de operação e etc. (HAYKIN; MOHER,
2010).

O protocolo Consumer Infrared (CIR) utiliza LEDs infravermelho que nada
mais são do que diodos emissores de luz no comprimento de onda do
infravermelho, utiliza também receptores infravermelhos de
encapsulamento único, que são circuitos integrados optoeletrônicos. Tais
receptores possuem toda a etapa óptica, lente, transdutor, etapa
eletrônica, filtro passa-faixa e amplificador, necessária para realizar
a recepção e demodulação do sinal infravermelho sem maiores complicações
(KAHN, 1994).

Estes receptores recebem infravermelho no comprimento de onda em torno
de 950nm, ou seja, dentro da categoria Near Infrared NIR/IR-A, mas só
amplificam os sinais que estejam modulados numa determinada frequência.
As frequências mais comuns nos modelos comerciais são 37kHz, 38kHz,
40kHz e 56kHz, embora esta última seja difícil de encontrar nos dias
atuais (ROCHOL, 2012).

Controle e Acionamentos
-----------------------

![image](https://user-images.githubusercontent.com/9977351/30784865-98b3ef6a-a133-11e7-8d77-a1e5c94acf53.png)

Fig. 1: Circuito de Potência e Acionamento

![image](https://user-images.githubusercontent.com/9977351/30784884-c40f484e-a133-11e7-8b65-61cde11d77a6.png)

Fig. 2: Circuito Lógico e de Controle

Programação em C
----------------

O microcontrolador foi programado utilizando a IDE Arduino, que é uma
plataforma de desenvolvimento de código aberto disponível em várias
versões no GitHub. A plataforma pode ser utilizada para a programação de
qualquer Arduino utilizando a linguagem C e possui diversas bibliotecas
disponíveis em também em código aberto para a integração de inúmeros
módulos e sensores.

Como supracitado foi utilizado a biblioteca “IRremote” para interfacear
a comunicação infravermelha, a biblioteca é suportada por grande parte
das placas Arduino, e seu o uso torna a programação simples. Após a
inserção da biblioteca é necessário declarar o “IRrecev” responsável por
ser o receptor de dados, informando o pino o qual está conectado o TSOP,
a partir deste ponto já estamos aptos a receber de dados. Precisamos
também declarar o “decode\_results*”* que será necessário para a
manipulação dos dados passados do TSOP para a porta digital. Na figura 3
é possível observar a inclusão da biblioteca e a declaração do receptor
do TSOP.

<span id="_Hlk481414933"
class="anchor"></span>![image](https://user-images.githubusercontent.com/9977351/30784891-d2e207e4-a133-11e7-8e21-9c1d6a72d007.png)

Fig. 3: IDE Arduino

A programação em C é simples e intuitiva, pois é feita de modo
estruturada, para projetos maiores também pode ser feito o uso de
orientação a objeto. O código foi escrito e refatorado de modo a ficar
de fácil manutenção, coeso e com um baixo acoplamento.

Na função de reprogramação de teclas, por sua vez é acionada por botões
ligados a portas digitais, que ao serem pressionados iniciam uma nova
rotina de duração predefinida onde aguarda uma nova entrada de dados
pelo TSOP em um tempo predefinido, caso seja recebido algum valor pelo
sensor esse novo valor será associado a variável de acionamento que
corresponda ao botão pressionado, caso não receba nenhum dado até o fim
do tempo definido nada acontece.

Indicativos de Aplicabilidade
=============================

O aumento em busca de novas tecnologias que possam simplificar o uso de
aparelhos eletrônicos no cotidiano propulsiona o mercado de automação e
controle. E essa busca que inicialmente partiu para setor industrial
excitou o público em geral a cada vez mais procurar itens que sejam
automatizados, de modo que possa proporcionar um maior conforto em suas
residências.

Pensando nessa necessidade de mercado foi idealizado um dispositivo de
acionamento genérico, de modo a atender a diversas aplicações com um
baixo custo de aquisição.

A comunicação infravermelha possui vantagens em meio a outras
tecnologias de comunicação sem fio, como o baixo custo que foi um fator
chave para a concepção de um protótipo que garante bons resultados a
custos que tornam a automação residencial possível para o mercado
brasileiro.

O dispositivo foi desenvolvido pensando em um ambiente como uma sala de
tv ou quarto, para efetuar o controle de dispositivos comuns a estes
ambientes em lares brasileiros como o um abajur e um ventilador. Assim
ao efetuar o controle a distância, o dispositivo proporciona conforto ao
usuário. Esta é a máxima agregadora de valor ao produto.

1.  Resultados e Discussões
    =======================

    1.  Protótipo 
        ----------

<span id="_Hlk481415143" class="anchor"></span>Por se tratar de um
protótipo, o circuito foi montado em uma placa perfurada de fenolite,
que é composta por uma matriz de furos e ilhas isoladas, de modo que as
trilhas do circuito são feitas utilizando preenchimento com solda
eletrônica em locais onde há a possibilidade de passagem de alta
corrente ou fios para contatos de baixa corrente, como pode ser
observado na figura 5. Essa escolha foi influenciada pela facilidade no
desenvolvimento da placa, pois o processo de desenvolvimento de uma
placa de circuito impresso seria dispendioso e oneroso quanto a criação
do design. A distribuição de componentes foi pensada para otimizar o
espaço a fim de que o dispositivo pudesse ser encaixado na caixa
idealizada como mostrado na figura 6.

<span id="_Hlk481415175"
class="anchor"></span>![image](https://user-images.githubusercontent.com/9977351/30784895-d611d76e-a133-11e7-86d3-912c711d91d2.png)Fig.
4: Protótipo do Circuito Lógico e de Controle, Vista Frontal

![image](https://user-images.githubusercontent.com/9977351/30784897-d93f5542-a133-11e7-803e-9c0f3ff29e88.png)

Fig. 5: Protótipo do Circuito Lógico e de Controle, Vista Traseira

Design
------

O protótipo foi concebido utilizando o conceito “design clean” \[9\]
onde se preza pelo aspecto limpo com poucos ou nenhum ornamento,
mantendo apenas aquilo é necessário, causando de pouca a nenhuma
interferência nos ambientes em que foram inseridos.

<span id="_Hlk481415487"
class="anchor"></span>![image](https://user-images.githubusercontent.com/9977351/30784899-dd2b1178-a133-11e7-8ef9-dbb2fda54613.png)

Fig. 6: Protótipo do Circuito Lógico e de Controle, Vista Traseira

<span id="_Hlk481415554" class="anchor"></span>A disposição do sensor
foi escolhida para que não houvesse superposição dos fios dos
dispositivos conectados, mantendo assim livre barreiras físicas que
pudessem atrapalhar a recepção de sinal enviados a ele. Os botões foram
colocados em um local de fácil acesso para que mesmo que com
dispositivos conectados fosse possível acionar suas funções.

Testes de Performance 
----------------------

<span id="_Hlk481415580" class="anchor"></span>O protótipo desenvolvido
está em uso a cerca de 4 meses em um ventilador de uso diário, e desde
então não foram observadas nenhuma falha no dispositivo. Que se mostrou
eficiente e econômico.

##### References

1.  <span id="_Hlk481415658" class="anchor"></span>HAYKIN, S.; VEEN, B.
    V.; **Signals and Systems**. Editora John Wiley and Sons; 2ª
    Edição, 2003.

2.  TORRES, J. L. O. Proposta de plataforma de baixo custo para redes ad
    hoc: Estudo de comunicação por infravermelho. **Trabalho de
    Conclusão de Curso**. Sobral: Universidade Federal do Ceará, Curso
    de Engenharia Elétrica, Centro de Tecnologia. 2015.

3.  ROCHOL, J. **Comunicação de Dados**. Dados eletrônicos. Porto
    Alegre, Editora Bookman, 2012.

4.  BARKER, P.; BOUCOUVALAS, A.C.; VITSAS, V. Performance modelling of
    the IrDA infrared wireless communications protocol. **In
    International Journal of Communication Systems**. 2002.

5.  KAHN, J. M.; BARRY, J. R.. **Wireless Infrared Communications**.
    Springer US, 1994.

6.  <span id="_Hlk481269244" class="anchor"></span>HAYKIN, S.; MOHER, M.
    **Sistemas de Comunicação**. Editora Bookman; 5ª Edição, 2010.

7.  Vishay Telefunken, “Photo Modules for PCM Remote Control Systems,”
    TSOP17… datasheet, Dez. 1998.

8.  Ken Shirriff. “Infrared remote library for Arduino: send and receive
    infrared signals with multiple protocols”. \[Online\]. Available:
    http://z3t0.github.io/Arduino-IRremote/

9.  Aponto Design, “Clean não é Branco,” 2016. Disponível em:
    &lt;http://apontodesign.com/blog/clean-nao-e-branco/&gt;.Acesso em
    20 de Abril de 2016.

10. Arduino, “Language Reference”. \[Online\]. Available:
    https://www.arduino.cc/en/Reference/HomePage
