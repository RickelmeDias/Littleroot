# Configurando meu Linux

#### Atualiza a lista de pacotes
`sudo apt-get update`

#### Instalação de pacotes essenciais
`sudo apt-get -y install build-essential default-jdk libssl-dev exuberant-ctags ncurses-term ack silversearcher-ag fontconfig imagemagick libmagickwand-dev software-properties-common git vim-gtk3 curl autoconf m4 libncurses5-dev libwgtk3.0-dev libgl1-mesa-dev libglu1-mesa-dev libpng-dev libssh-dev unixodbc-dev xsltproc fop zsh`

#### Zsh

###### Configuração do Zsh
`sudo chsh -s $(which zsh)`

caso o bash não inicie ao abrir o terminal podes tentar:

- https://askubuntu.com/questions/131823/how-to-make-zsh-the-default-shell

no caso, eu fiz:

1. Alteração no arquivo:

>
>Open /etc/passwd:
>
>`sudo vi /etc/passwd`
>
>Find the line with your username:
>
>`username:x:1634231:100:Your Name:/home/username:/bin/bash`
>
>and replace bash with zsh:
>
>`username:x:1634231:100:Your Name:/home/username:/bin/zsh`
>

2. Também é possivel fazer: `sudo chsh -s /bin/zsh $USER`, o meu resolveu até aqui, mas foi necessario `reboot`.

e depois dar um `reboot`.

###### Instalação de plugins para o Zsh
1. zsh-syntax-highlighting: `git clone https://github.com/zsh-users/zsh-autosuggestions $ZSH_CUSTOM/plugins/zsh-autosuggestions`
2. zsh-autosuggestions: `git clone https://github.com/zsh-users/zsh-autosuggestions ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-autosuggestions`
3. fzf: `git clone --depth 1 https://github.com/junegunn/fzf.git ~/.fzf && ~/.fzf/install`

###### Instalação do asdf (assumindo que você quer instalar o asdf)
1. `git clone https://github.com/asdf-vm/asdf.git ~/.asdf --branch v0.13.1`
2. `. "$HOME/.asdf/asdf.sh"`

###### Edição do arquivo .zshrc para adicionar plugins

`sudo nano ~/.zshrc`

```
plugins=(
  git
  zsh-syntax-highlighting
  zsh-autosuggestions
  fzf
)
```

###### Mudar de tema

`sudo nano ~/.zshrc`

```
ZSH_THEME="daveverwer"
```

#### Instalando Ambiente

Instalando o [asdf](https://asdf-vm.com/guide/getting-started.html): `git clone https://github.com/asdf-vm/asdf.git ~/.asdf --branch v0.13.1`

Adicionar ao `~/.baschrc`
1. `. "$HOME/.asdf/asdf.sh"`
2. `. "$HOME/.asdf/completions/asdf.bash"`

E no `~/.zshrc`
1. `. "$HOME/.asdf/asdf.sh"`
   
- Para ver todos plugins de asdf: `asdf plugin list all`
- Para adicionar plugins: `asdf plugin add <name> <git-url>` ou `asdf plugin add <name>`
- Para ver apenas as versões de uma linguagem, caso não tenha um latest: `asdf list-all java`

Linguagens a serem instaladas:

1. `asdf install nodejs latest`
2. `asdf install rust latest`
3. Java 8: `asdf install java adoptopenjdk-8.0.181+13`
4. Java 11: `asdf install java openjdk-11`
5. Java 17: `asdf install java openjdk-11`
6. `asdf install golang latest`

Agora adicione as versões como sendo a global do seu ambiente (você pode alterar de acordo com  a necessidade):

1. `asdf global nodejs latest`
2. `asdf global rust latest`
3. `asdf global java openjdk-11`
4. `asdf global golang latest`

Se quiser ver as versões instaladas de uma linguagem, no exemplo java, você pode: `asdf list java`

Exemplo, se você tem um projeto Java da versão 1.8, você pode fazer dentro da pasta desse projeto o comando: `asdf local java adoptopenjdk-8.0.181+13`, que para aquele projeto será rodado o java 8.

###### Para o Python:

Antes de instalar python verificar pacotes e acompanhar instalação para ver se está correta:

1. `sudo apt-get update`
2. `sudo apt-get install make build-essential libssl-dev zlib1g-dev libbz2-dev libreadline-dev libsqlite3-dev wget curl llvm libncurses5-dev xz-utils tk-dev libxml2-dev libxmlsec1-dev libffi-dev liblzma-dev`

Depois pode instalar:

1. `asdf install python 3.10.6`
2. `asdf global python 3.10.6`
3. Então o comando `python --version` deverá mostrar Python 3.10.6

#### Instalando Docker

###### Adicionar "Docker's official GPG key":
1. `sudo apt-get update`
2. `sudo apt-get install ca-certificates curl gnupg`
3. `sudo install -m 0755 -d /etc/apt/keyrings`
4. `curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /etc/apt/keyrings/docker.gpg`
5. `sudo chmod a+r /etc/apt/keyrings/docker.gpg`

###### Adidiconando repositorio:
  1. `echo "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.gpg] https://download.docker.com/linux/ubuntu $(. /etc/os-release && echo "$VERSION_CODENAME") stable" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null` 

ou

```
echo \
  "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.gpg] https://download.docker.com/linux/ubuntu \
  $(. /etc/os-release && echo "$VERSION_CODENAME") stable" | \
  sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
```
2. `sudo apt-get update`

###### Instalando

1. `sudo apt-get install docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin`

###### Dando permissão ao docker

1. `sudo usermod -aG docker $USER`

Imporantate Reiniciar! Então: `reboot`


#### Gerandno ssh

1. `ssh-keygen -o -a 100 -t ed25519 -f ~/.ssh/id_ed25519 -C "email@email.email"`

#### Configurando o Git

1. `git config --global user.name "Seu Nome"`
2. `git config --global user.email "email@email.email"`

#### Configurando o Ambiente de Código

1. `sudo apt install tmux`
2. `sudo apt install tilix`
3. `asdf install ruby 2.6.3`
4. `asdf global ruby 2.6.3`
5. Instalar os dotfiles YADR: https://github.com/skwp/dotfiles#readme
