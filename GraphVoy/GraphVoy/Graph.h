#pragma once
#include <vector>
#include <iostream>
#include <limits>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <queue>

#ifndef M_PI
#define M_PI 3.14/*159265358979323846*/
#endif

template<typename T>
struct Vertex {
	sf::CircleShape shape;
	T value;
	sf::Text text;
};

template<typename T>
struct Edge {
	sf::Vertex line[2];
	sf::Text text;
};

template<typename T>
class Graph
{
public:
	Graph() {}
	Graph(const int& size);
	~Graph(){}
	void insertEdge(const T& vert_1, const T& vert_2, int weight); 
	void insertVertex(const T& vert);
	void deleteVertex(){ this->vertList.pop_back(); }
	int getAmountEdges();
	int getAmountVertexes() { return this->vertexV.size(); }
	bool isFull() { return this->vertexV.size() == this->maxSize; }
	bool isEmpty() { return this->vertexV.size() == 0; }
	int getVertexPos(const T& vert);
	int getWeight(const T& vert_1, const T& vert_2);
	std::vector<T> getNbrs(const T& vert);
	void print();
	void dijkstra(const Graph<T>& graph, const T& source);
	void DFS(T& startVertex, bool* visitedVertes);
	void BFS(T& startVertex, bool* visitedVertes);
	void visualizeGraph(Graph<T>& graph);
private:
	std::vector<T> vertexV;
	std::vector<std::vector<int>> adjMatrix;
	int maxSize;
	bool isAddingVertex = false; // Флаг для добавления вершины
	bool isAddingEdge = false; // Флаг для добавления ребра
	T selectedVertex; // Выбранная вершина для добавления ребра
	std::queue<T> VertexQ;
};

template<typename T>
Graph<T>::Graph(const int& size)
{
	this->maxSize = size;
	this->adjMatrix = std::vector<std::vector<T>>(size, std::vector<T>(size));

	for (int i = 0; i < this->maxSize; i++)
	{
		for (int j = 0; j < this->maxSize; j++)
			this->adjMatrix[i][j] = 0;
	}
}

template<typename T>
void Graph<T>::insertEdge(const T & vert_1, const T & vert_2, int weight)
{
	if (getVertexPos(vert_1) != -1 && this->getVertexPos(vert_2) != -1)
	{
		int vertPos_1 = getVertexPos(vert_1);
		int vertPos_2 = getVertexPos(vert_2);

		if (this->adjMatrix[vertPos_1][vertPos_2] != 0
		&& this->adjMatrix[vertPos_2][vertPos_1] != 0)
		{
			std::cout << "The Edge between verts already exist" << std::endl;
			return;
		}
		else
		{
			adjMatrix[vertPos_1][vertPos_2] = weight;
			adjMatrix[vertPos_2][vertPos_1] = weight;
		}
	}
	else
	{
		std::cout << "Two(or one of them) verts doesnt exist in graph" << std::endl;
		return;
	}
}

template<typename T>
void Graph<T>::insertVertex(const T& vert)
{
	if (this->isFull())
	{
		std::cout << "Cant add vert" << std::endl;
		return;
	}
	this->vertexV.push_back(vert);
}

template<typename T>
int Graph<T>::getAmountEdges()
{
	int amount = 0;
	if (!this->isEmpty())
	{
		for (int i = 0; i < this->vertexV.size(); i++)
		{
			for (int j = 0; j < this->vertexV.size(); j++)
				if (this->adjMatrix[i][j] != 0) amount++;
		}
	}
	return amount / 2;
}

template<typename T>
int Graph<T>::getVertexPos(const T& vert)
{
	for (int i = 0; i < this->vertexV.size(); i++)
	{
		if (this->vertexV[i] == vert) return i;
	}
	return -1;
}

template<typename T>
int Graph<T>::getWeight(const T& vert_1, const T& vert_2)
{
	if (this->isEmpty()) return 0;

	int vert_1Pos = this->getVertexPos(vert_1);
	int vert_2Pos = this->getVertexPos(vert_2);

	if (vert_1Pos == -1 || vert_2Pos == -1)
	{
		std::cout << "One of Node doesnt exist" << std::endl;
		return 0;
	}
	return this->adjMatrix[vert_1Pos][vert_2Pos];
}

template<typename T>
std::vector<T> Graph<T>::getNbrs(const T& vert)
{
	std::vector<T> NbrsVect;
	int pos = this->getVertexPos(vert);
	if (pos != -1)
	{
		for (int i = 0; i < this->vertexV.size(); i++)
			if (this->adjMatrix[pos][i] != 0) 
				NbrsVect.push_back(this->vertexV[i]);
	}
	return NbrsVect;
}

template<typename T>
void Graph<T>::print()
{
	if (!this->isEmpty())
	{
		std::cout << "Adjustment Matrix: " << std::endl;
		std::cout << "   ";
		for (int i = 0; i < vertexV.size(); i++)
			std::cout << vertexV[i] << "  ";
		std::cout << std::endl;

		for (int i = 0; i < this->vertexV.size(); i++)
		{
			std::cout << this->vertexV[i] << " ";
			for (int j = 0; j < this->vertexV.size(); j++)
				std::cout << " " << this->adjMatrix[i][j] << " ";
			std::cout << std::endl;
		}
	}
	else std::cout << "Graph is empty" << std::endl;
}

template<typename T>
void Graph<T>::dijkstra(const Graph<T>& graph, const T& source) {
	int n = getAmountVertexes();

	std::vector<int> distances(n, std::numeric_limits<int>::max());
	distances[getVertexPos(source)] = 0;

	std::vector<bool> visited(n, false);

	for (int i = 0; i < n - 1; i++) {
		int minDistance = std::numeric_limits<int>::max();
		int minIndex = -1;

		for (int j = 0; j < n; j++) {
			if (!visited[j] && distances[j] < minDistance) {
				minDistance = distances[j];
				minIndex = j;
			}
		}

		if (minIndex == -1)
			break;

		visited[minIndex] = true;
		std::vector<T> neighbors = getNbrs(graph.vertexV[minIndex]);

		for (const T& neighbor : neighbors) {
			int neighborPos = getVertexPos(neighbor);
			int weight = getWeight(graph.vertexV[minIndex], neighbor);

			if (!visited[neighborPos] && distances[minIndex] != std::numeric_limits<int>::max()
				&& distances[minIndex] + weight < distances[neighborPos]) {
				distances[neighborPos] = distances[minIndex] + weight;
			}
		}
	}

	// Вывод кратчайших расстояний от исходной вершины до всех остальных вершин
	std::cout << "Кратчайшие расстояния от вершины " << source << ":\n";
	for (int i = 0; i < n; i++) {
		if (distances[i] == std::numeric_limits<int>::max()) {
			std::cout << "Вершина " << graph.vertexV[i] << " недостижима" << std::endl;
		}
		else {
			std::cout << "Расстояние до вершины " << graph.vertexV[i] << ": " << distances[i] << std::endl;
		}
	}
}

template<typename T>
void Graph<T>::DFS(T& startVertex, bool* visitedVertes)
{
	std::cout << "Vertex " << startVertex << " is visited\n";
	visitedVertes[this->getVertexPos(startVertex)] = true;
	std::vector<T> neighbors = this->getNbrs(startVertex);
	for (int i = 0; i < neighbors.size(); i++)
	{
		if (!visitedVertes[this->getVertexPos(neighbors[i])])
			this->DFS(neighbors[i], visitedVertes);
	} 
}

template<typename T>
void Graph<T>::BFS(T& startVertex, bool* visitedVertes)
{
	
	if (visitedVertes[this->getVertexPos(startVertex)] == false)
	{
		this->VertexQ.push(startVertex);
		std::cout << "Vertex " << startVertex << " is complete\n";
		visitedVertes[this->getVertexPos(startVertex)] = true;
	}

	std::vector<T> neighbors = this->getNbrs(startVertex);
	this->VertexQ.pop();
	for (int i = 0; i<neighbors.size(); i++)
	{
		if (!visitedVertes[this->getVertexPos(neighbors[i])])
		{
			this->VertexQ.push(neighbors[i]);
			visitedVertes[this->getVertexPos(neighbors[i])] = true;
			std::cout << "Vertex " << neighbors[i] << " is complete\n";
		}
	}
	if (this->VertexQ.empty()) return;
	BFS(VertexQ.front(), visitedVertes);

}

template<typename T>
void Graph<T>::visualizeGraph(Graph<T>& graph) {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Graph Visualization");
	window.setFramerateLimit(60);

	// Создание вершин
	std::vector<Vertex<T>> vertices;
	int numVertices = graph.getAmountVertexes();
	float radius = 200.0f;
	float centerX = 400.0f;
	float centerY = 300.0f;
	
	sf::Font font;
	font.loadFromFile("arial.ttf");

	for (int i = 0; i < numVertices; i++) {
		float angle = static_cast<float>(i) * (2.0f * M_PI / numVertices);
		float x = centerX + radius * std::cos(angle);
		float y = centerY + radius * std::sin(angle);

		//Задание вершины
		Vertex<T> vertex;
		vertex.shape.setPosition(x, y);
		vertex.shape.setRadius(30.0f);
		vertex.shape.setFillColor(sf::Color::White);
		vertex.shape.setOutlineThickness(2.0f);
		vertex.shape.setOutlineColor(sf::Color::Black);
		vertex.value = graph.vertexV[i];

		//Добавление номера вершины в круг
		sf::Text text(std::to_string(vertex.value), font, 20);
		text.setFillColor(sf::Color::Black);
		text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
		text.setPosition(vertex.shape.getPosition() + sf::Vector2f(vertex.shape.getRadius(), vertex.shape.getRadius()));
		vertex.text = text;

		vertices.push_back(vertex);
	}

	// Создание ребер
	std::vector<Edge<T>> edges;

	for (int i = 0; i < numVertices; i++) {
		T vertexValue = graph.vertexV[i];
		std::vector<T> neighbors = graph.getNbrs(vertexValue);

		for (const T& neighbor : neighbors) {
			Edge<T> edge;
			int vertexIndex = graph.getVertexPos(vertexValue);
			int neighborIndex = graph.getVertexPos(neighbor);

			sf::Vector2f vertexCenter = vertices[vertexIndex].shape.getPosition() + sf::Vector2f(vertices[vertexIndex].shape.getRadius(), 
				vertices[vertexIndex].shape.getRadius());
			sf::Vector2f neighborCenter = vertices[neighborIndex].shape.getPosition() + sf::Vector2f(vertices[neighborIndex].shape.getRadius(),
				vertices[neighborIndex].shape.getRadius());

			edge.line[0].position = vertexCenter;
			edge.line[0].color = sf::Color::Black;
			edge.line[1].position = neighborCenter;
			edge.line[1].color = sf::Color::Black;

			// Определение позиции для отображения текста
			sf::Vector2f startPos = edge.line[0].position;
			sf::Vector2f endPos = edge.line[1].position;
			sf::Vector2f Move(0, 15);
			sf::Vector2f textPos = Move + startPos + (endPos - startPos) / 2.0f;

			// Отображение текста с весом ребра над линией
			sf::Text text(std::to_string(graph.getWeight(vertexIndex + 1, neighborIndex + 1)), font, 16);
			text.setFillColor(sf::Color::Black);
			text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
			text.setPosition(textPos);
			edge.text = text;

			edges.push_back(edge);
		}
	}

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);
		drawGraph(window, graph, vertices, edges);
	}
}