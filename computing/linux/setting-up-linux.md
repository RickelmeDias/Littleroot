# Configurando meu Linux

#### Atualiza a lista de pacotes
`sudo apt-get update`

#### Instalação de pacotes essenciais
`sudo apt-get -y install build-essential default-jdk libssl-dev exuberant-ctags ncurses-term ack silversearcher-ag fontconfig imagemagick libmagickwand-dev software-properties-common git vim-gtk3 curl autoconf m4 libncurses5-dev libwgtk3.0-dev libgl1-mesa-dev libglu1-mesa-dev libpng-dev libssh-dev unixodbc-dev xsltproc fop zsh`

#### Zsh

###### Configuração do Zsh
`sudo chsh -s $(which zsh)`

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

- Para ver todos plugins de asdf: `asdf plugin list all`
- Para adicionar plugins: `asdf plugin add <name> <git-url>` ou `asdf plugin add <name>`
- Para ver apenas as versões de uma linguagem, caso não tenha um latest: `asdf list-all java`

Linguagens a serem instaladas:

1. `asdf install nodejs latest`
2. `asdf install rust latest`
3. `asdf install java latest`
4. `asdf install golang latest`

###### Para o Python:

Antes de instalar python verificar pacotes e acompanhar instalação para ver se está correta:

`sudo apt install build-essential zlib1g-dev libncurses5-dev libgdbm-dev libnss3-dev libssl-dev libreadline-dev libffi-dev wget`

Depois pode instalar:

`asdf install python latest`

Adicionar ao `~/.baschrc`
1. `. "$HOME/.asdf/asdf.sh"`
2. `. "$HOME/.asdf/completions/asdf.bash"`

E no `~/.zshrc`
1. `. "$HOME/.asdf/asdf.sh"`

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

`sudo apt-get install docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin`

###### Dando permissão ao docker

`sudo usermod -aG docker $USER`


#### Gerandno ssh

`ssh-keygen -o -a 100 -t ed25519 -f ~/.ssh/id_ed25519 -C "email@email.email"`

## Imporantate Reiniciar! Então:

`reboot`
