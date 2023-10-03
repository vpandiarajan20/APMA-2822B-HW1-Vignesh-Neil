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
##SBATCH -o output/matMul-basicO3-1-%j.out
#SBATCH -o output/matMul-contiguousO3-8-%j.out
#SBATCH -e output/matMul-error-%j.out
#----- End of slurm commands ----

# Run a command
# ./matMul basic 1
./matMul contiguous 8


# contiguous normal
# noncontiguous normal
# contiguous (O1 & O3 optimizations) 
# contigous no optimization (2 rolls)
# noncontigous (O1 & O3)