# Modelo OSI 

O modelo osi é um padrão internacional definidas pela organização internacional chamada ISO.

O modelo OSI (Open System Interconnectino), foi definida para que um computador possa se comunicar com outro computador.


São 7 camadas ao todo

- 7 - Camada Aplicação
    - é utilizada pelos aplicativos que vão enviar os arquivos necessários, seja ele um servidor de email, um browser.
- 6 -Camada de apresentação
    - Ela recebe a informação da camada de aplicação e então provê uma formatação, seu objetivo é fazer com que maquinas que rodem sistemas operacionais diferentes consigam compreender a mesma mensagem.
- 5 - Camada de sessão
    - Serve para estabelecer uma sessão entre as máquinas para que dure mais do que um pacote entre elas.
- 4 - Camada de Transporte
    - Responsável em garantir a confiança do pacote, ou seja, ela garante que o pacote chegara ao seu destino contendo todos os dados necessários tanto da informação como da identificação de sua origem.
- 3 - Camada de Rede
    - Serve para roteamente,  normalmente onde usa o tcp/ip, ela auxilia os roteadores a encaminhar para máquina certa.
- 2 - Camada de Enlace
    - Onde contem o endereço MAC e Switches, semelhante a camada 3, ela auxilia também no endereçamento correto do pacote ao seu destino final.
- 1 - Camada Física
    - Onde toda a governança de cabos, hubs, repetidores, meio físico acontece.

---

## Camada Física

Ela determina a parte física, o tipo de conector e a característica da rede. A camada física não compreende o conteúdo que está transportando, uma vez, que ela recebe apenas pulsos eletrícos onde cada pulso representa 0 e 1.

-----

## Camada de Enlace

Na camada de enlace se identifica o tamanho do pacote.
também é capaz de identificar erros de transmissão ou colisões entre pacotes.
Também é onde aparece o endereçamento único. (MAC Address)
MAC Address é um endereço único é como uma digital que identifica a placa.

-----

## Camada de Rede

Proporciona o roteamento de pacotes entre redes, alguns protocolos como o IP, IPX são identificados. A duas coisas importentes que essa camada implementa, o endereçamento lógico e o roteamento.
Endereçamento lógico é o que nós conhecemos como o endereço IP, ele característica qual é a rede local e o host. (192.168.1.3)

---

## Camada de Transporte
É responsável pelo transporte de um local ao outro por meio de protocolos
TCP = Transmition control protocol, garante que uma mensagem seja enviado.
UDP = User datagram protocol.
A diferença entra o TCP e o UDP, é que o TCP, ele envia um pacote antes de enviar os dados e espera uma resposta do outro lado da conexão, assim ela garante que o pacote será entregue difente do UDP que apenas envia, mas não há uma confirmação de recebimento do pacote,  essa abordagem é conhecida como Three-Way Handshake, ou aperto de mãos  em portugues. Sendo assim, a vantagem do UDP sobre o TCP é a sua velocidade de transmissão, pois há menos pacotes sendo enviados aumentando assim a sua eficiencia, entretanto, todavia, porém... do outro lado, a vantagem do TCP sobre o UDP é a garantia da conexão, aumentando assim a sua confiabilidade que o pacote será entregue.

-----

## Camada de Sessão

Enquanto que a camada 4 identifica se um pacote chegou no seu destino ou não, na camada 5 irá estabelecer a conversa entre os hosts.

-----

## Camada de Apresentação

Ela é responsável por formatar as mensagem antes de ir para a camada de aplicação ( camada 7).
A camada 6 pode trabalhar com a conversão, compressão e criptografia de dados.


---

## Camada de Aplicação

A camada de aplicação não é onde os aplicativos são executados, e sim, uma interface de comunicação em rede. 
Os principais protocolos que trabalham nessa camada são:

- DNS
    - Protocolo responsável por resolver os nomes de dominios retornando o endereço IP.
- FTP
    - Protocolo de comunicação que faz transferencia de arquivos entre duas máquinas,
- HTTP
    - Protocolo responsável pela transferencia de paginas, não possui criptografia dos dados.
- HTTPS
    - Protocolo responsável pela transferencia de paginas, possuí criptografia dos dados.
- SMTP
    - Protocolo responsável pelo envio de mensagens de email
- POP3
    - Protocolo responsável pelo recebimento de mensagens de email, ela faz os downlods das mensagens do servidor para a máquina local
- IMAP 
    - Protocolo responsável pelo recebimento de mensagens de email, não faz downlods das mensagens, mas sincroniza com o servidor.
- TELNET
    - Protocolo responsável por testar a conectividade de uma porta uma porta de serviço e a configuração de uma máquina remotamente.





##### YEA BABY, THANK U.
