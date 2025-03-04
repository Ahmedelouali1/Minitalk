What is signals?

its a way of communicationg between processes  especially betweeen the kernel and other processes to notify them with an event

pid?

  pid "hwa a unique id kaykon 3nd kola process dyalo kytst3ml bach y identify lprocess 3amatan , o ktst3mlof kill bach tspecifyi ina process bghiti tsift lih signal"
    howa li haz lina process id dyal li ghansifto lih lmsg.

Difference Between SIGUSR1 and SIGUSR2

    lfar9  hwa lokkhrin kyts3mlhom  system o kola w7da defined l wa7d l7aja (sig int hya interrupt sig stop ktstopi process ...) wlkin sigusr 1 o 2 mkyst3mlhomch system home mdyorin l user bach yst3mlhom kima bgha.

check_pid katchecki lina wach kayna gha + w7da o ila kan mn b3d dik + \0 y3ni ra kayna + bo7dha which is invalid o mn b3d tantchekiw wach kayn ar9am wla la 

Input: +abc       --> Invalid

Input: +1223      --> Valid

Input: -315448    --> Valid

Input: +          --> Invalid

Input: +++84848   --> Invalid

Input: --45       --> Invalid

Input: +-67       --> Invalid

Input: ++89       --> Invalid

Input: 123        --> Valid

nisanfdan invalid

sf
send_msg kador 3la string o katsift char by char b send_char
send_char kat7wal lina mn decimal lbinnary
o katchecki dak lbit wach 0 wla 1 bach tsift lina ya SIGUSR1 wla SIGUR2
kill katsift lina signal lwa8d lprocees li lid dyalo howa li wst ()
kola process endi f pc dyali endo id dyalo
system call hwa type of function li kay requesti mn os(operating system) ydir wa7d task li lprocess dyalk m3ndoch premission lih example write read ... aya 7aja kt7taj interaction m3a hardware


aya process fach kywsslo aya signal kyterminati (kymot) ila bghtit tbedel lbehavior dyalo mni ywslo chi signal ktst3mal signal ola sigaction , chnahoma had signal o sigaction , hado function kykhaliwk anaka tbadal chno ghyw9a3  mni yjik wa7d signal 
signal(SIGINT, funtion_1hna w9tma ghadi tjik sigint (ctrl + c ) ghadi truna l function_1 blast mn anaho ymot process dyalk
nafs l3iba ta f sigaction lfar9 binathom hwa anaho sigaction kt3tik info ktar , kt3tik chkon li sift lik dak signal (process id dyalo)
3lach ghatfidk f minitalk 7itach nta ktsendi f client sigusr1 o sigusr2 wlkin la siftihom l process ghadi ghi ytkila o safi nta baghi thandlihom bach mni ywslk sig1 z3ma rah sift lik bit0 o la kant sig2 ra sift lik bit 1

signal and sigaction?

    signal basic function bach thandli lbehavior d process mni yreceivi signal , sigaction kadir nafs l 7aja wlkin kt3tik more info 3la chkon li sift lik signal chnahwa pid dyalo ....)
    wlkin sigusr 1 o 2 mkyst3mlhomch system home mdyorin l user bach yst3mlhom kima bgha

why we use usleep?
  7it khask dir wa7d pause bin tsifit d signals 7it ila sifti bzaf mtab3in kytlosaw o ktwsl ghi w7da machi kytsafo o kaywslo kamlin


void sig_handler(int sig)
{
    static int i;
    static char c;
    int arr[8] = {1, 2, 4, 8, 16, 32, 64, 128};

    if (sig == SIGUSR1)
    {
        c += arr[i];
        i++;
    }
    if (sig == SIGUSR2)
    {                                          
        ila kan sig =usr 2 y3ni andir 2 os i mdroba f 0 li hya 0 y3ni mghanzido walo 3la dik c
ghadi ghir nzido i 7it wslatna bit akhra
        i++;
    }
}


if (pid <= 1)
    return (1);
    what happens if you give kill function pid 0 or 1 or negative value ?


Conclusion :

bima anaho t9ad tsift ghi joj d signals y3ni khask tkhdem b binary , y3ni atsift  kola character 3la form d binary ila kan 1 atsift sig1 matalan o ila kan 0 atsfift sig2 , t9der tglebhom mayhemch , o f server li ghyreceivi w9tma atjih sig1 ay7sab ra wa7d o w9tma atjih sig2 ay7sab rah 0 , o w9tma ywsloh 8 d signals kt3ni anaho wslato character kaml (character fih 1 byte li fiha 8 d bits == 8 signals) hwa ghadi y printi dak character o yred dakchi l 0 bach y2awed l7sab mn lwel
