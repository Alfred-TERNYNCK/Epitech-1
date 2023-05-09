FROM node:12-alpine
WORKDIR /app
COPY . /app
RUN npm install body-parser cookie-parser express method-override async pg socket.io
EXPOSE 80
CMD ["node", "server.js"]
