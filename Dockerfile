# Use slim debian as base image
FROM debian:buster-slim

# Install gcc compiler and build tools
RUN apt-get update && apt-get install -y --no-install-recommends \
    gcc \
    build-essential \
    rm -rf /var/lib/apt/lists/*

# create new linux user for execution
RUN useradd -ms /bin/bash dns

# change the working directory and user
WORKDIR /home/dns
USER dns 

# Copy the source files into the image
# ...
# Compile the source code
RUN make

# Run the application at container launch
# ...



