﻿#include "Framework.h"
#include "Camera.h"

Camera::Camera() :
	position(0, 0, 0),
	forward(0, 0, 1),
	up(0, 1, 0),
	right(1, 0, 0),
	rotation(0, 0, 0),
	matView(g_matIdentity),
	matRotation(g_matIdentity)
{
	Rotation();
	Move();
}

Camera::~Camera()
{
}

void Camera::Position(float x, float y, float z)
{
	position = Vector3(x, y, z);
	Move();
}

void Camera::Position(Vector3& vec)
{
	position = vec;
	Move();
}

void Camera::GetPosition(Vector3* vec)
{
	*vec = position;
}

void Camera::GetMatrix(Matrix* matrix)
{
	memcpy(matrix, &matView, sizeof Matrix);
}

void Camera::Rotation(float x, float y, float z)
{
	rotation = Vector3(x, y, z);
	Rotation();
}

void Camera::Rotation(Vector3& vec)
{
	rotation = vec;
	Rotation();
}

void Camera::GetRotation(Vector3* vec)
{
	*vec = rotation;
}

void Camera::RotationDegree(float x, float y, float z)
{
	rotation = Vector3(x, y, z) * Math::PI / 180.0f;
	Rotation();
}

void Camera::RotationDegree(Vector3& vec)
{
	rotation = vec * Math::PI / 180.0f;
	Rotation();
}

void Camera::GetRotationDegree(Vector3* vec)
{
	*vec = rotation * 180.0f / Math::PI;
}

void Camera::View()
{
	D3DXMatrixLookAtLH(&matView, &position, &(position + forward), &up);
}

void Camera::Move()
{
	View();
}

void Camera::Rotation()
{
	Matrix X, Y, Z;
	D3DXMatrixRotationX(&X, rotation.x);
	D3DXMatrixRotationY(&Y, rotation.y);
	D3DXMatrixRotationZ(&Z, rotation.z);

	matRotation = X * Y * Z;
	D3DXVec3TransformNormal(&forward, &Vector3(0, 0, 1), &matRotation);
	D3DXVec3TransformNormal(&right, &Vector3(1, 0, 0), &matRotation);
	D3DXVec3TransformNormal(&up, &Vector3(0, 1, 0), &matRotation);
}