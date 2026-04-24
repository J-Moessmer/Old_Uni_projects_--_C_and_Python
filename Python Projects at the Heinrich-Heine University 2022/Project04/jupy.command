#!/usr/bin/env bash
# Check for anaconda directory and start jupyter notebook
# Raphael Bialon <bialon@cs.uni-duesseldorf.de> 2017

if [[ -z $HOME ]]; then
    echo "Error: \$HOME is empty, exiting..."
    exit 1
fi

if [[ -d "$HOME/anaconda3" ]]; then
    ANACONDA_DIR="$HOME/anaconda3"
elif [[ -d "$HOME/anaconda" ]]; then
    ANACONDA_DIR="$HOME/anaconda"
elif [[ -d "$HOME/opt/anaconda3" ]]; then
    ANACONDA_DIR="$HOME/opt/anaconda3"
elif [[ -d /opt/anaconda3 ]]; then
    ANACONDA_DIR=/opt/anaconda3
else
    echo "No valid anaconda directory found, exiting..."
    exit 1
fi

NOTEBOOK_DIR=$(dirname "$0")

${ANACONDA_DIR}/bin/jupyter-notebook --NotebookApp.iopub_data_rate_limit=1.0e10 --notebook-dir "$NOTEBOOK_DIR"

