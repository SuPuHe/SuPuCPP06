/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:55:02 by omizin            #+#    #+#             */
/*   Updated: 2025/12/09 16:41:22 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr) { return reinterpret_cast<uintptr_t>(ptr); }

Data* Serializer::deserialize(uintptr_t raw) { return reinterpret_cast<Data*>(raw); }
