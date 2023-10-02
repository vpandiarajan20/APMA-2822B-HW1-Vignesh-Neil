#!/bin/bash
# This is a bash script, so any line that starts with # is
# a comment.  If you need to comment out an #SBATCH line 
# use ##SBATCH 
#
# To submit this script to slurm do:
#    sbatch hello.sh
#
# --- Start of slurm commands -----------
# Request an hour of runtime:
#SBATCH --time=0:05:00
# Default resources are 1 core with 2.8GB of memory.
# Use more memory (4GB):
#SBATCH --mem=16G
# Specify a job name:
#SBATCH -J APMA2822B-matMul
# Specify an output file
# %j is a special variable that is replaced by the JobID when 
# job starts
#SBATCH -o matMul-basic-%j.out
##SBATCH -o matMul-contiguous-%j.out
#SBATCH -e matMul-%j.out
#----- End of slurm commands ----

# Run a command
./matMul basic
# ./matMul contiguous