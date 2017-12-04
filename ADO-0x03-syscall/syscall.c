execve(const char *filename, char *const argv[],
                  char *const envp[]);/*

Executa o programa apontado pelo nome do arquivo. Nome do arquivo deve
ser um executável binário, ou um script que comece com uma linha da forma: #! interpreter [optional-arg]

argv é uma série de strings de argumento passadas para o novo programa.
De convenção, a primeira dessas strings (ou seja, argv [0] ) deve conter o nome do arquivo
associado ao arquivo que está sendo executado.
envp é um matriz de strings, convencionalmente da forma key=value.
Os argv e envp matrizes cada um deve incluir um ponteiro nulo no final da matriz.
*/

brk(void *addr); /*

Alteram a localização da interrupção do programa , que define o fim do segmento de dados do processo
(ou seja, o programa break é o primeiro local após o fim dos dados não inicializados segmento).
Aumentar a interrupção do programa tem o efeito de alocar memória do processo; diminuir a interrupção desaloca a memória.

sbrk () incrementa o espaço de dados do programa por bytes de incremento.
Chamar sbrk () com um incremento de 0 pode ser usado para encontrar a corrente localização da interrupção do programa.
*/

access(const char *pathname, int mode);/*

Verifica se o processo de chamada pode acessar o nome do caminho do arquivo.
Se pathname for um link simbólico, ele é desreferenciado.
O modo especifica as verificações de acessibilidade a serem executadas e é ou o valor F_OK,
ou uma máscara consistindo no OR bit a bit de um ou mais de R_OK , W_OK e X_OK.
F_OK prova a existência do Arquivo.
R_OK , W_OK e X_OK testam se o arquivo existe e conceder, escrever e executar permissões, respectivamente.
*/


open(const char *pathname, int flags);/*

A chamada do sistema aberto () abre o arquivo especificado pelo nome do caminho .
Se o O arquivo especificado não existe, ele pode opcionalmente
(se O_CREAT for especificado em flags ) seja criado por open ().
O valor de retorno de open () é um descritor de arquivo, um pequeno,
não negativo número inteiro que é usado nas chamadas subseqüentes do
sistema ( leia (2), escreva (2), lseek (2), fcntl (2), etc.) para se referir ao arquivo aberto.
O arquivo o descritor retornado por uma chamada bem-sucedida será o número mais
baixo O descritor de arquivo atualmente não está aberto para o processo.
*/

fstat(int fd, struct stat *statbuf);/*

Essas funções retornam informações sobre um arquivo, no buffer apontado por statbuf.
Não são necessárias permissões no arquivo em si, mas - no caso de stat (), fstatat () e lstat () -
execute (pesquisa) é necessária em todos os diretórios no caminho que levam ao arquivo.

fstat () é idêntico ao stat (), exceto que o arquivo sobre o qual a informação a ser
recuperada é especificada pelo descritor do arquivo fd .
*/


close(int fd); /*

close () fecha um descritor de arquivo, para que ele não se refira mais a nenhum arquivo e pode ser reutilizado.
Qualquer bloqueio de registro mantido no O arquivo com o qual foi associado e possuído pelo processo foi removido.
*/

read(int fd, void *buf, size_t count);/*

read () tenta ler para contar bytes do descritor de arquivo fd no buffer a partir de buf.
Nos arquivos que suportam a busca, a operação de leitura começa no offset de arquivo e o
deslocamento do arquivo é incrementado pelo número de bytes lidos.
Se o deslocamento do arquivo estiver em ou passado o final do arquivo, não bytes são lidos, e read () retorna zero.
*/


mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);/*

cria um novo mapeamento no espaço de endereço virtual do processo de chamada.
O endereço de partida para o novo mapeamento é especificado em addr.
O argumento de comprimento especifica o comprimento do apeamento (que deve ser maior que 0).
Se addr for NULL, o kernel escolherá o endereço para qual criar o mapeamento;
Este é o método mais portátil de criar um ovo mapeamento.
Se addr não for NULL, então o kernel o aceita como uma sugestão sobre onde colocar o mapeamento; no Linux,
o mapeamento será criado em um limite de página próximo. O endereço do novo mapeamento é retornou como resultado da chamada.
*/

mprotect(void *addr, size_t len, int prot);/*

altera as proteções de acesso para o processo de chamada páginas de memória contendo qualquer
parte do intervalo de endereços no intervalo [ addr , addr + len -1].
addr deve ser alinhado a um limite de página.
Se o processo de chamada tentar acessar a memória de uma maneira que viola as proteções,
então o kernel gera um sinal SIGSEGV para o processo.
*/

arch_prctl(int code, unsigned long addr);/*

define o processo específico da arquitetura ou o estado da thread.
o código seleciona uma subfunção e passa o argumento addr a ele;
addr é interpretado como um sinal não assinado para as operações "set",
ou como um sinal não assinado * , para as operações "get".
*/

munmap(void *addr, size_t length);/*

cria um novo mapeamento no espaço de endereço virtual do processo de chamada.
O endereço de partida para o novo mapeamento é especificado em addr.
O argumento de comprimento especifica o comprimento do mapeamento (que deve ser maior que 0).
Se addr for NULL, o kernel escolherá o endereço para qual criar o mapeamento;
Este é o método mais portátil de criar um novo mapeamento.
Se addr não for NULL, então o kernel o aceita como uma sugestão sobre onde colocar o mapeamento;
no Linux, o mapeamento será criado em um limite de página próximo.
O endereço do novo mapeamento é retornou como resultado da chamada.
*/

write(int fd, const void *buf, size_t count);/*

Grava para contar bytes do buffer iniciando em buf para  o arquivo mencionado pelo descritor de arquivo fd.
*/

exit_group(int status); /*

Essa chamada do sistema é equivalente a _exit (2), exceto que ele termina não apenas o tópico de chamada,
mas todos os tópicos no processo de chamada grupo de discussão.
*/
